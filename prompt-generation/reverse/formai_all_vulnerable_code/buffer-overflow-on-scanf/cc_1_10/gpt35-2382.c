//FormAI DATASET v1.0 Category: Sudoku solver ; Style: detailed
#include <stdio.h>

int grid[9][9];

// Function to check if a value can be placed in a cell
int isSafe(int row, int col, int num) {
    // Check if the same number exists in the row
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }
    // Check if the same number exists in the column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }
    // Check if the same number exists in the 3x3 box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    // If the number can be placed in the cell, return 1
    return 1;
}

// Function to solve the Sudoku puzzle
int solve(int row, int col) {
    // If the row is 9, we have reached the end of the puzzle
    if (row == 9) {
        return 1;
    }
    // If the column is 9, move to the next row
    if (col == 9) {
        return solve(row + 1, 0);
    }
    // If the cell is not empty, move to the next column
    if (grid[row][col] != 0) {
        return solve(row, col + 1);
    }
    // Try placing numbers from 1 to 9 in the cell
    for (int i = 1; i <= 9; i++) {
        if (isSafe(row, col, i)) {
            grid[row][col] = i;
            if (solve(row, col + 1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    // If no number can be placed in the cell, backtrack
    return 0;
}

int main() {
    printf("Enter the Sudoku puzzle:\n");
    // Taking input from the user
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    // Solving the Sudoku puzzle
    if (solve(0, 0)) {
        printf("Solution:\n");
        // Printing the solution
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }
    return 0;
}