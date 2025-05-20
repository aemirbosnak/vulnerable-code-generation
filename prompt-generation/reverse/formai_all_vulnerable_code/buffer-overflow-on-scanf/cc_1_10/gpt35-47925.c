//FormAI DATASET v1.0 Category: Sudoku solver ; Style: retro
#include <stdio.h>

// Function to check if a number is valid in a cell
int isValid(int sudoku[9][9], int row, int col, int num) {
    // Check if num appears in the same row
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == num) {
            return 0;
        }
    }

    // Check if num appears in the same column
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == num) {
            return 0;
        }
    }

    // Check if num appears in the same 3x3 box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[boxRow + i][boxCol + j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to solve sudoku puzzle recursively
int solveSudoku(int sudoku[9][9], int row, int col) {
    if (row == 9) {
        row = 0;
        col++;
        if (col == 9) {
            return 1;
        }
    }

    // Skip over pre-filled cells
    if (sudoku[row][col] != 0) {
        return solveSudoku(sudoku, row+1, col);
    }

    // Try numbers 1-9 in current cell
    for (int i = 1; i <= 9; i++) {
        if (isValid(sudoku, row, col, i)) {
            sudoku[row][col] = i;
            if (solveSudoku(sudoku, row+1, col)) {
                return 1;
            }
        }
    }

    // Backtrack if no solution found
    sudoku[row][col] = 0;
    return 0;
}

// Function to print sudoku grid
void printSudoku(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
            if (j == 2 || j == 5) {
                printf("| ");
            }
        }
        printf("\n");
        if (i == 2 || i == 5) {
            printf("---------------------\n");
        }
    }
}

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

    printf("Welcome to Retro Sudoku!\n");
    printf("Enter the puzzle one row at a time, using 0 for blank cells.\n");

    // Get input from user and populate sudoku grid
    for (int i = 0; i < 9; i++) {
        printf("Row %d: ", i+1);
        for (int j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }

    // Solve sudoku puzzle
    int solved = solveSudoku(sudoku, 0, 0);
    if (solved) {
        printf("\nSolution:\n");
        printSudoku(sudoku);
    } else {
        printf("\nNo solution found!\n");
    }

    return 0;
}