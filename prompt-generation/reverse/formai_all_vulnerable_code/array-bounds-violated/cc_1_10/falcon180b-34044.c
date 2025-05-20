//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define TOTAL_CELLS (ROWS * COLS)

#define EMPTY 0
#define WATER 1
#define BLOCKED 2

int grid[ROWS][COLS];

void initializeGrid() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = BLOCKED;
        }
    }
    grid[0][0] = WATER;
}

void printGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == EMPTY) {
                printf("  ");
            } else if (grid[i][j] == WATER) {
                printf("X ");
            } else {
                printf("B ");
            }
        }
        printf("\n");
    }
}

void percolate() {
    int row = 0;
    int col = 0;
    int neighbors = 0;
    int count = 0;

    while (count < TOTAL_CELLS) {
        if (row == ROWS - 1 || col == COLS - 1) {
            if (grid[row][col] == WATER) {
                grid[row][col] = EMPTY;
                count++;
            }
        } else {
            neighbors = 0;
            if (grid[row][col] == WATER) {
                if (grid[row + 1][col] == EMPTY) {
                    neighbors++;
                }
                if (grid[row][col + 1] == EMPTY) {
                    neighbors++;
                }
                if (grid[row - 1][col] == EMPTY) {
                    neighbors++;
                }
                if (grid[row][col - 1] == EMPTY) {
                    neighbors++;
                }
            }

            if (neighbors >= 2) {
                grid[row][col] = EMPTY;
                count++;
            } else {
                grid[row][col] = BLOCKED;
            }
        }

        row++;
        if (row == ROWS - 1) {
            row = 0;
            col++;
        }
    }
}

int main() {
    initializeGrid();
    printGrid();
    percolate();
    printGrid();

    return 0;
}