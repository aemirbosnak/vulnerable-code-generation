//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complex
#include <stdio.h>
#define SIZE 9

int sudoku[SIZE][SIZE];

// function to check if a value is valid in a specific cell
int isValid(int row, int col, int val) {
    // check row and column
    for (int i = 0; i < SIZE; i++) {
        if (sudoku[row][i] == val || sudoku[i][col] == val) {
            return 0;
        }
    }
    // check square
    int squareRow = (row / 3) * 3;
    int squareCol = (col / 3) * 3;
    for (int i = squareRow; i < squareRow + 3; i++) {
        for (int j = squareCol; j < squareCol + 3; j++) {
            if (sudoku[i][j] == val) {
                return 0;
            }
        }
    }
    return 1;
}

// recursive function to solve the sudoku
int solveSudoku(int row, int col) {
    int nextRow = row, nextCol = col + 1;
    if (nextCol == SIZE) {
        nextRow++;
        nextCol = 0;
    }
    if (row == SIZE) {
        return 1;
    }
    if (sudoku[row][col] != 0) {
        return solveSudoku(nextRow, nextCol);
    }
    for (int i = 1; i <= SIZE; i++) {
        if (isValid(row, col, i)) {
            sudoku[row][col] = i;
            if (solveSudoku(nextRow, nextCol)) {
                return 1;
            }
        }
    }
    sudoku[row][col] = 0;
    return 0;
}

int main() {
    // input sudoku grid
    printf("Enter the Sudoku grid (use 0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
    // solve sudoku
    if (solveSudoku(0, 0)) {
        // print solution
        printf("Solution:\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution!");
    }
    return 0;
}