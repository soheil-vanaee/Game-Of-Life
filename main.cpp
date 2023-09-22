#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

const int SIZE = 90; 
const int ROWS = SIZE;
const int COLS = SIZE;



void draw(bool world[ROWS][COLS]) {
    system("clear"); 

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (world[i][j]) {
                std::cout << "•"; 
                // std::cout << "🐛"; 
            } else {
                std::cout << " "; 
            }
        }
        std::cout << std::endl;
    }
}

void evolve(bool world[ROWS][COLS]) {
    bool newWorld[ROWS][COLS] = {false};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {

            int liveNeighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    int newX = i + x;
                    int newY = j + y;
                    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS) {
                        if (world[newX][newY]) {
                            liveNeighbors++;
                        }
                    }
                }
            }
            if (world[i][j]) {
                if (liveNeighbors == 2 || liveNeighbors == 3) {
                    newWorld[i][j] = true;
                }
            } else {
                if (liveNeighbors == 3) {
                    newWorld[i][j] = true;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            world[i][j] = newWorld[i][j];
        }
    }
}

int main() {
    bool world[ROWS][COLS] = {false};
    srand(time(nullptr));

    for (int i = 0; i < 2000; i++) {
        int x = rand() % ROWS;
        int y = rand() % COLS;
        world[x][y] = true;
    }

    while (true) {
        draw(world);
        evolve(world);
        usleep(100000); 
    }

    return 0;
}

