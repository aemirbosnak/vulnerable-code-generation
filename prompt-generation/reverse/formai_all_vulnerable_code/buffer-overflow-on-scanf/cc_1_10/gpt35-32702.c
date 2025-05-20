//FormAI DATASET v1.0 Category: Sudoku solver ; Style: dynamic
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 9

// Helper function to print the Sudoku grid
void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    printf("-----------------------------\n");
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            printf("%d ", grid[row][col]);
            if ((col + 1) % 3 == 0) printf("| ");
        }
        printf("\n");
        if ((row + 1) % 3 == 0) printf("-----------------------------\n");
    }
}

// Helper function to check if a number can be placed in a certain position in the grid
bool isPossible(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num) {
    // Check if the number already exists in the row or column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    // Check if the number already exists in the 3x3 sub-grid
    int subGridRow = row - (row % 3);
    int subGridCol = col - (col % 3);
    for (int i = subGridRow; i < subGridRow + 3; i++) {
        for (int j = subGridCol; j < subGridCol + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Recursive function to solve the Sudoku puzzle
bool solveSudoku(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    // Check if we have reached the end of the grid
    if (row == GRID_SIZE) {
        return true;  // Sudoku has been solved successfully
    }
    // Check if we have reached the end of a row
    if (col == GRID_SIZE) {
        return solveSudoku(grid, row + 1, 0);
    }
    // Check if the current cell is already filled
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }
    // Try to place a number from 1 to 9 in the current cell
    for (int num = 1; num <= 9; num++) {
        if (isPossible(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return true;  // Sudoku has been solved successfully
            }
            grid[row][col] = 0;  // Backtrack
        }
    }
    return false;  // Sudoku cannot be solved with this configuration
}

int main() {
    printf("Enter the Sudoku grid:\n");
    int grid[GRID_SIZE][GRID_SIZE];
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            scanf("%d", &grid[row][col]);
        }
    }
    printf("Input grid:\n");
    printGrid(grid);
    if (solveSudoku(grid, 0, 0)) {
        printf("\nSolution:\n");
        printGrid(grid);
    } else {
        printf("\nSudoku cannot be solved.\n");
    }
    return 0;
}