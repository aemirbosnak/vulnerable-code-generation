//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: innovative
#include <stdio.h>

#define BOARD_SIZE 9

void solveSudoku(int board[][BOARD_SIZE], int n) {
    int row, col, i, j, k, val;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                for (val = 1; val <= BOARD_SIZE; val++) {
                    if (checkValid(board, val, i, j)) {
                        board[i][j] = val;
                        solveSudoku(board, n);
                        board[i][j] = 0;
                    }
                }
                return;
            }
        }
    }
}

int checkValid(int board[][BOARD_SIZE], int val, int row, int col) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == val) return 0;
        if (board[row][i] == val) return 0;
        if (board[val / BOARD_SIZE * BOARD_SIZE + i][col] == val) return 0;
    }
    for (j = 0; j < BOARD_SIZE; j++) {
        if (board[row][j] == val) return 0;
        if (board[j][val / BOARD_SIZE * BOARD_SIZE + col] == val) return 0;
        if (board[val / BOARD_SIZE * BOARD_SIZE + row][j] == val) return 0;
    }
    return 1;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int n;
    printf("Enter the size of the board: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    solveSudoku(board, n);
    printf("Sudoku Solved:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}