//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

void printGrid(int grid[SIZE][SIZE]);
bool findEmptyLocation(int grid[SIZE][SIZE], int *row, int *col);
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num);
bool solveSudoku(int grid[SIZE][SIZE]);

int main() {
    int grid[SIZE][SIZE];

    printf("Enter the Sudoku puzzle (0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Original Sudoku Puzzle:\n");
    printGrid(grid);

    if (solveSudoku(grid)) {
        printf("\nSolved Sudoku Puzzle:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}

void printGrid(int grid[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int d = 0; d < SIZE; d++) {
            printf("%d ", grid[r][d]);
        }
        printf("\n");
    }
}

bool findEmptyLocation(int grid[SIZE][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true; // Found an empty location
            }
        }
    }
    return false; // No empty location
}

bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check the row
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check the column
    for (int x = 0; x < SIZE; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check the 3x3 subgrid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int r = 0; r < 3; r++) {
        for (int d = 0; d < 3; d++) {
            if (grid[r + startRow][d + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;

    // If there is no empty space, we are done
    if (!findEmptyLocation(grid, &row, &col)) {
        return true;
    }

    // Try numbers 1 through 9
    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(grid, row, col, num)) {
            // Assigning the number and trying for the next empty space
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true; // If successful, return true
            }

            // If it doesn't lead to a solution, reset the cell and try next number
            grid[row][col] = 0;
        }
    }

    return false; // Triggers backtracking
}