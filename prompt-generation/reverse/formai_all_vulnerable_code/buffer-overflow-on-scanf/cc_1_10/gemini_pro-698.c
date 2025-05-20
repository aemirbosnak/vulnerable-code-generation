//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int board[9][9];

int is_safe(int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }

    int box_row = row / 3;
    int box_col = col / 3;

    for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku(int row, int col) {
    if (row == 9) {
        return 1;
    }

    if (col == 9) {
        return solve_sudoku(row + 1, 0);
    }

    if (board[row][col] != 0) {
        return solve_sudoku(row, col + 1);
    }

    for (int i = 1; i <= 9; i++) {
        if (is_safe(row, col, i)) {
            board[row][col] = i;

            if (solve_sudoku(row, col + 1)) {
                return 1;
            } else {
                board[row][col] = 0;
            }
        }
    }

    return 0;
}

int main() {
    int i, j;

    printf("Enter the Sudoku puzzle:\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    if (solve_sudoku(0, 0)) {
        printf("The solved Sudoku puzzle is:\n");
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists for the given Sudoku puzzle.\n");
    }

    return 0;
}