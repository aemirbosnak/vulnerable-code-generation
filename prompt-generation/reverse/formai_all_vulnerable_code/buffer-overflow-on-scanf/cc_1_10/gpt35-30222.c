//FormAI DATASET v1.0 Category: Sudoku solver ; Style: all-encompassing
#include <stdio.h>

#define N 9 // size of the grid

int sudoku[N][N];

// function to print the Sudoku grid
void printSudoku() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if it is safe to place the digit d in the position (row, col)
int isSafe(int row, int col, int d) {
    // check row
    for (int i = 0; i < N; i++) {
        if (sudoku[row][i] == d) {
            return 0;
        }
    }
    // check column
    for (int i = 0; i < N; i++) {
        if (sudoku[i][col] == d) {
            return 0;
        }
    }
    // check 3x3 subgrid
    int subgridRow = (row / 3) * 3;
    int subgridCol = (col / 3) * 3;
    for (int i = subgridRow; i < subgridRow + 3; i++) {
        for (int j = subgridCol; j < subgridCol + 3; j++) {
            if (sudoku[i][j] == d) {
                return 0;
            }
        }
    }
    return 1;
}

// function to solve the Sudoku recursively
int solveSudoku(int row, int col) {
    if (row == N) { // all rows have been filled
        return 1;
    }
    if (col == N) { // last column of the current row, move to next row
        return solveSudoku(row + 1, 0);
    }
    if (sudoku[row][col] != 0) { // current cell is already filled, move to next cell
        return solveSudoku(row, col + 1);
    }
    // try all digits from 1 to 9 in the current cell
    for (int d = 1; d <= 9; d++) {
        if (isSafe(row, col, d)) {
            sudoku[row][col] = d;
            if (solveSudoku(row, col + 1)) { // move to next cell
                return 1;
            }
            sudoku[row][col] = 0; // backtrack, try the next digit
        }
    }
    return 0;
}

int main() {
    // initialize Sudoku grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
    printf("Input:\n");
    printSudoku();
    // solve Sudoku
    if (solveSudoku(0, 0)) {
        printf("Solution:\n");
        printSudoku();
    }
    else {
        printf("No solution exists.\n");
    }
    return 0;
}