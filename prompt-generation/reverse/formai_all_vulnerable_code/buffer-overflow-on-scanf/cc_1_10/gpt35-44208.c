//FormAI DATASET v1.0 Category: Sudoku solver ; Style: surprised
#include <stdio.h>

// Function to print the Sudoku grid
void printSudoku(int sudoku[9][9]) {
    printf("___________________\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                printf("| ");
            }
            printf("%d ", sudoku[i][j]);
        }
        printf("|\n");
        if ((i + 1) % 3 == 0) {
            printf("-------------------\n");
        }
    }
    printf("___________________\n");
}

// Function to check if the given value can be placed in the specified cell
int canPlace(int sudoku[9][9], int row, int col, int val) {
    int i, j, stRow, stCol;
    // Check if the value already exists in the same row or column
    for (i = 0; i < 9; i++) {
        if (sudoku[row][i] == val || sudoku[i][col] == val) {
            return 0;
        }
    }
    // Check if the value already exists in the same 3x3 subgrid
    stRow = (row / 3) * 3;
    stCol = (col / 3) * 3;
    for (i = stRow; i < stRow + 3; i++) {
        for (j = stCol; j < stCol + 3; j++) {
            if (sudoku[i][j] == val) {
                return 0;
            }
        }
    }
    // Return 1 if the value can be placed in the specified cell
    return 1;
}

// Recursive function to solve the Sudoku puzzle
int solveSudoku(int sudoku[9][9], int row, int col) {
    int i, j, val;
    // Check if the current cell is the last cell of the grid
    if (row == 8 && col == 9) {
        return 1;
    }
    // Check if the current column is the last column of the row
    if (col == 9) {
        col = 0;
        row++;
    }
    // Check if the current cell is already filled
    if (sudoku[row][col] != 0) {
        return solveSudoku(sudoku, row, col + 1);
    }
    // Try all possible values for the current cell
    for (i = 1; i <= 9; i++) {
        if (canPlace(sudoku, row, col, i)) {
            sudoku[row][col] = i;
            // Recursively solve the puzzle by moving on to the next cell
            if (solveSudoku(sudoku, row, col + 1)) {
                return 1;
            }
            // If the current solution fails, reset the current cell and try the next value
            sudoku[row][col] = 0;
        }
    }
    return 0;
}

// Main function
int main() {
    int sudoku[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    // Ask the user to enter the Sudoku puzzle
    printf("Please enter the Sudoku puzzle (use 0 for empty cells):\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
    // Print the initial Sudoku grid
    printf("\nInitial Sudoku grid:\n");
    printSudoku(sudoku);
    // Solve the Sudoku puzzle
    if (solveSudoku(sudoku, 0, 0)) {
        // Print the solved Sudoku grid
        printf("\nSolved Sudoku grid:\n");
        printSudoku(sudoku);
    } else {
        printf("\nNo solution exists for the given Sudoku puzzle.\n");
    }
    return 0;
}