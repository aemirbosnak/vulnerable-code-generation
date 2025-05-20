//FormAI DATASET v1.0 Category: Sudoku solver ; Style: ultraprecise
#include <stdio.h>

// Function to print the sudoku grid
void printGrid(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the number is safe to place in the cell
int isSafe(int grid[9][9], int row, int col, int num) {
    // Check if the number is already present in the row, column or 3x3 grid
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num ||
            grid[row - row % 3 + i / 3][col - col % 3 + i % 3] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to solve the sudoku grid
int solveSudoku(int grid[9][9], int row, int col) {
    // If we have reached the end of the grid, return true
    if (row == 9) {
        return 1;
    }

    // If we have reached the end of the row, move to the beginning of the next row
    if (col == 9) {
        return solveSudoku(grid, row + 1, 0);
    }

    // If the cell is already filled, move to the next cell
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }

    // Try all the possible numbers (1-9)
    for (int num = 1; num <= 9; num++) {
        // Check if the number is safe to be placed in the cell
        if (isSafe(grid, row, col, num)) {
            // Place the number in the cell
            grid[row][col] = num;

            // Try to solve the remaining grid
            if (solveSudoku(grid, row, col + 1)) {
                return 1;
            }

            // If the solution is not possible with the current number, remove the number from the cell
            grid[row][col] = 0;
        }
    }

    // If none of the numbers work, backtrack and try with a different number
    return 0;
}

// Driver program
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

    // Input the sudoku grid
    printf("Enter the sudoku grid:\n");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            scanf("%d", &grid[row][col]);
        }
    }

    // Solve the sudoku grid
    if (solveSudoku(grid, 0, 0)) {
        printf("Solution:\n");
        printGrid(grid);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}