//FormAI DATASET v1.0 Category: Sudoku solver ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the Sudoku grid
void printGrid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the given value is already present in the row
bool isInRow(int grid[9][9], int row, int num) {
    for (int col = 0; col < 9; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

// Function to check if the given value is already present in the column
bool isInCol(int grid[9][9], int col, int num) {
    for (int row = 0; row < 9; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

// Function to check if the given value is already present in the 3x3 box
bool isInBox(int grid[9][9], int startRow, int startCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + startRow][col + startCol] == num) {
                return true;
            }
        }
    }
    return false;
}

// Function to check if it's safe to put the given value in the given position
bool isSafe(int grid[9][9], int row, int col, int num) {
    return !isInRow(grid, row, num) && !isInCol(grid, col, num) && !isInBox(grid, row - row % 3, col - col % 3, num);
}

// Function to find the next unassigned position in the Sudoku grid
bool findEmptyPosition(int grid[9][9], int* row, int* col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Function to solve the Sudoku grid
bool solveSudoku(int grid[9][9]) {
    int row, col;
    if (!findEmptyPosition(grid, &row, &col)) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

// main function
int main() {
    int grid[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    printf("Enter the Sudoku grid (0 for empty cells):\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    if (solveSudoku(grid)) {
        printf("The solution to the Sudoku is:\n");
        printGrid(grid);
    } else {
        printf("No solution exists for the given Sudoku.\n");
    }
    return 0;
}