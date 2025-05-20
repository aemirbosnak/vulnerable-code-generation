//FormAI DATASET v1.0 Category: Sudoku solver ; Style: immersive
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 9

int grid[GRID_SIZE][GRID_SIZE];

bool findUnassignedLocation(int *row, int *col) {
    for (*row = 0; *row < GRID_SIZE; (*row)++) {
        for (*col = 0; *col < GRID_SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool usedInRow(int row, int num) {
    for (int col = 0; col < GRID_SIZE; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool usedInColumn(int col, int num) {
    for (int row = 0; row < GRID_SIZE; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool usedInBox(int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row+boxStartRow][col+boxStartCol] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int row, int col, int num) {
    return !usedInRow(row, num) &&
           !usedInColumn(col, num) &&
           !usedInBox(row - row % 3, col - col % 3, num) &&
           grid[row][col] == 0;
}

bool solveSudoku() {
    int row, col;

    if (!findUnassignedLocation(&row, &col)) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku()) {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false;
}

void printGrid() {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    // Sample inputs
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            scanf("%d", &grid[row][col]);
        }
    }

    if (solveSudoku()) {
        printGrid();
    } else {
        printf("No solution found\n");
    }

    return 0;
}