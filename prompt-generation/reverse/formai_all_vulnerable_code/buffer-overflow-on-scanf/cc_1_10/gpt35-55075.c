//FormAI DATASET v1.0 Category: Sudoku solver ; Style: standalone
#include <stdio.h>

#define SIZE 9

int valid(int sudoku[SIZE][SIZE], int row, int col, int num) {
    // Check row
    for (int i = 0; i < SIZE; i++) {
        if (sudoku[row][i] == num) {
            return 0;
        }
    }
    // Check column
    for (int i = 0; i < SIZE; i++) {
        if (sudoku[i][col] == num) {
            return 0;
        }
    }
    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[startRow + i][startCol + j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve(int sudoku[SIZE][SIZE], int row, int col) {
    if (row == SIZE) {
        return 1;
    }
    if (col == SIZE) {
        return solve(sudoku, row + 1, 0);
    }
    if (sudoku[row][col] != 0) {
        return solve(sudoku, row, col + 1);
    }
    for (int num = 1; num <= SIZE; num++) {
        if (valid(sudoku, row, col, num)) {
            sudoku[row][col] = num;
            if (solve(sudoku, row, col + 1)) {
                return 1;
            }
        }
    }
    sudoku[row][col] = 0;
    return 0;
}

void printSudoku(int sudoku[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int sudoku[SIZE][SIZE] = {
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

    printf("Enter the comma-separated values of the sudoku puzzle (0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }

    if (solve(sudoku, 0, 0)) {
        printf("Solved sudoku puzzle:\n");
        printSudoku(sudoku);
    } else {
        printf("No solution exists for the given sudoku puzzle.\n");
    }

    return 0;
}