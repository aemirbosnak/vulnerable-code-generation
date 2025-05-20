//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

void print_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool is_valid(int board[SIZE][SIZE], int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    int start_row = row - row % 3;
    int start_col = col - col % 3;

    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool sudoku_solver(int board[SIZE][SIZE]) {
    int row, col;

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= SIZE; num++) {
                    if (is_valid(board, row, col, num)) {
                        board[row][col] = num;

                        if (!sudoku_solver(board)) {
                            board[row][col] = 0;
                        }
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main() {
    int board[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    if (!sudoku_solver(board)) {
        printf("Invalid Sudoku board.\n");
    } else {
        print_board(board);
    }

    return 0;
}