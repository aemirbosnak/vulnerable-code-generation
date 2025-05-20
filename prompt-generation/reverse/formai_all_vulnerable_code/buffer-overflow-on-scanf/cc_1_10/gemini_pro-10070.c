//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define SUDOKU_SIZE 9

int sudoku[SUDOKU_SIZE][SUDOKU_SIZE];

int is_valid(int row, int col, int val) {
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        if (sudoku[row][i] == val) {
            return 0;
        }
        if (sudoku[i][col] == val) {
            return 0;
        }
    }

    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
            if (sudoku[i][j] == val) {
                return 0;
            }
        }
    }

    return 1;
}

int solve(int row, int col) {
    if (row == SUDOKU_SIZE) {
        return 1;
    }

    if (col == SUDOKU_SIZE) {
        return solve(row + 1, 0);
    }

    if (sudoku[row][col] != 0) {
        return solve(row, col + 1);
    }

    for (int val = 1; val <= SUDOKU_SIZE; val++) {
        if (is_valid(row, col, val)) {
            sudoku[row][col] = val;
            if (solve(row, col + 1)) {
                return 1;
            }
        }
    }

    sudoku[row][col] = 0;
    return 0;
}

int main() {
    printf("Enter the Sudoku puzzle:\n");
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }

    if (solve(0, 0)) {
        printf("The solved Sudoku puzzle is:\n");
        for (int i = 0; i < SUDOKU_SIZE; i++) {
            for (int j = 0; j < SUDOKU_SIZE; j++) {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("The Sudoku puzzle is unsolvable.\n");
    }

    return 0;
}