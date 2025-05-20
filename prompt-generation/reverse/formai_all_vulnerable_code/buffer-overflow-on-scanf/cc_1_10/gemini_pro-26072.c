//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 9

int board[BOARD_SIZE][BOARD_SIZE];

int is_valid(int row, int col, int value) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == value) {
            return 0;
        }
    }

    for (j = 0; j < BOARD_SIZE; j++) {
        if (board[row][j] == value) {
            return 0;
        }
    }

    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;

    for (i = start_row; i < start_row + 3; i++) {
        for (j = start_col; j < start_col + 3; j++) {
            if (board[i][j] == value) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku() {
    int row, col, value;

    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == 0) {
                for (value = 1; value <= BOARD_SIZE; value++) {
                    if (is_valid(row, col, value)) {
                        board[row][col] = value;

                        if (solve_sudoku()) {
                            return 1;
                        }

                        board[row][col] = 0;
                    }
                }

                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int i, j;

    printf("Enter the Sudoku puzzle:\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    if (solve_sudoku()) {
        printf("The solved Sudoku puzzle is:\n");

        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                printf("%d ", board[i][j]);
            }

            printf("\n");
        }
    } else {
        printf("The Sudoku puzzle cannot be solved.\n");
    }

    return 0;
}