//FormAI DATASET v1.0 Category: Sudoku solver ; Style: careful
#include <stdio.h>

int grid[9][9]; // Global array to hold sudoku grid

// Function to check if a number is already present in a row
int checkRow(int row, int num) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return 1; // Number already exists in row
        }
    }
    return 0; // Number does not exist in row
}

// Function to check if a number is already present in a column
int checkCol(int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return 1; // Number already exists in column
        }
    }
    return 0; // Number does not exist in column
}

// Function to check if a number is already present in a 3x3 square
int checkSquare(int row, int col, int num) {
    int startRow = (row / 3) * 3; // Starting row of the 3x3 square
    int startCol = (col / 3) * 3; // Starting column of the 3x3 square
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (grid[i][j] == num) {
                return 1; // Number already exists in 3x3 square
            }
        }
    }
    return 0; // Number does not exist in 3x3 square
}

// Function to check if a number can be placed in a cell
int isSafe(int row, int col, int num) {
    if (checkRow(row, num) || checkCol(col, num) || checkSquare(row, col, num)) {
        return 0; // Number cannot be placed in cell
    }
    return 1; // Number can be placed in cell
}

// Function to solve the sudoku using backtracking
int solveSudoku() {
    int row, col, num;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                for (num = 1; num <= 9; num++) {
                    if (isSafe(row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku()) {
                            return 1; // Sudoku solved successfully
                        }
                        grid[row][col] = 0; // Undo the current cell for backtracking
                    }
                }
                return 0; // Unable to solve sudoku
            }
        }
    }
    return 1; // Sudoku already solved
}

int main() {
    int i, j;
    printf("Enter the sudoku grid (Use 0 for blank spaces):\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    if (solveSudoku()) {
        printf("\nThe solution to the sudoku is:\n");
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nUnable to solve the sudoku. Please enter a valid input.\n");
    }
    return 0;
}