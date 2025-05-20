//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Function prototypes
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num);
bool findEmptyLocation(int grid[SIZE][SIZE], int *row, int *col);
bool solveSudoku(int grid[SIZE][SIZE]);
void printGrid(int grid[SIZE][SIZE]);

int main() {
    int grid[SIZE][SIZE];

    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (solveSudoku(grid)) {
        printf("Solved Sudoku:\n");
        printGrid(grid);
    } else {
        printf("No solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int d = 0; d < SIZE; d++) {
            printf("%d ", grid[r][d]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed in the grid
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to find an empty location in the grid
bool findEmptyLocation(int grid[SIZE][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;

    if (!findEmptyLocation(grid, &row, &col)) {
        return true; // Sudoku is solved
    }

    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num; // Assign num to the grid

            if (solveSudoku(grid)) {
                return true; // Found solution
            }

            grid[row][col] = 0; // Backtrack if no solution found
        }
    }
    return false; // Triggers backtracking
}