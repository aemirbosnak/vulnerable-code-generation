//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100
#define BOARD_SIZE WIDTH * HEIGHT

int main() {
    int i, j;
    int board[BOARD_SIZE];
    int rules[2][2] = {{0, 1}, {1, 0}};
    int grid[BOARD_SIZE];
    int numNeighbors;
    int aliveNeighbors;
    int state;

    // Initialize the board with random cells
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i + j * WIDTH] = rand() % 2;
        }
    }

    // Calculate the number of live neighbors for each cell
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            numNeighbors = 0;
            for (int k = -1; k < 2; k++) {
                for (int l = -1; l < 2; l++) {
                    if (i + k >= 0 && i + k < BOARD_SIZE && j + l >= 0 && j + l < BOARD_SIZE) {
                        if (board[i + k + j * WIDTH] == 1) {
                            numNeighbors++;
                        }
                    }
                }
            }
            if (board[i + j * WIDTH] == 1 && numNeighbors == 2 || board[i + j * WIDTH] == 0 && numNeighbors == 3) {
                grid[i + j * WIDTH] = 1;
            } else {
                grid[i + j * WIDTH] = 0;
            }
        }
    }

    // Print the initial state of the board
    printf("Initial state:\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", grid[i + j * WIDTH]);
        }
        printf("\n");
    }

    // Simulate the next generation
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            state = grid[i + j * WIDTH];
            aliveNeighbors = 0;
            for (int k = -1; k < 2; k++) {
                for (int l = -1; l < 2; l++) {
                    if (i + k >= 0 && i + k < BOARD_SIZE && j + l >= 0 && j + l < BOARD_SIZE) {
                        if (grid[i + k + j * WIDTH] == 1) {
                            aliveNeighbors++;
                        }
                    }
                }
            }
            if (state == 1 && (aliveNeighbors == 2 || aliveNeighbors == 3)) {
                grid[i + j * WIDTH] = 1;
            } else if (state == 0 && aliveNeighbors == 3) {
                grid[i + j * WIDTH] = 1;
            }
        }
    }

    // Print the next generation of the board
    printf("Next generation:\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", grid[i + j * WIDTH]);
        }
        printf("\n");
    }

    return 0;
}