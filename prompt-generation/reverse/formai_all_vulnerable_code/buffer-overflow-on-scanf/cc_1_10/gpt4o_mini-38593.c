//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: real-life
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int r = 0; r < SIZE; r++) {
        for (int d = 0; d < SIZE; d++) {
            printf("%d ", grid[r][d]);
        }
        printf("\n");
    }
}

// Check if the number is not in the current row
bool isSafeInRow(int grid[SIZE][SIZE], int row, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

// Check if the number is not in the current column
bool isSafeInColumn(int grid[SIZE][SIZE], int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (grid[row][col] == num) {
            return false;
        }
    }
    return true;
}

// Check if the number is not in the current 3x3 box
bool isSafeInBox(int grid[SIZE][SIZE], int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + startRow][col + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

// Check if it's safe to place the number at the given position
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    return isSafeInRow(grid, row, num) &&
           isSafeInColumn(grid, col, num) &&
           isSafeInBox(grid, row - row % 3, col - col % 3, num);
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) { // Find an empty space
                for (int num = 1; num <= SIZE; num++) { // Try numbers 1 to 9
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num; // Place the number
                        if (solveSudoku(grid)) { // Recursively solve
                            return true;
                        }
                        grid[row][col] = 0; // Reset on failure
                    }
                }
                return false; // Trigger backtracking
            }
        }
    }
    return true; // Solved
}

// Function to read Sudoku input
void readSudoku(int grid[SIZE][SIZE]) {
    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
}

int main() {
    int grid[SIZE][SIZE];
    
    readSudoku(grid);
    
    printf("\nInitial Sudoku Grid:\n");
    printGrid(grid);
    
    if (solveSudoku(grid)) {
        printf("\nSolved Sudoku Grid:\n");
        printGrid(grid);
    } else {
        printf("No solution exists for the given Sudoku puzzle.\n");
    }
    
    return 0;
}