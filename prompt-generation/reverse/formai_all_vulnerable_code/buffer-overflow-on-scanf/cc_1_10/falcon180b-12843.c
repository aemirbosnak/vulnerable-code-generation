//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

void print_board(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int board[SIZE][SIZE], int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }

    int box_row = row - row % 3;
    int box_col = col - col % 3;

    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int backtrack(int board[SIZE][SIZE], int row, int col) {
    if (col == SIZE) {
        col = 0;
        row++;
    }

    if (row == SIZE) {
        return 1;
    }

    if (col > SIZE) {
        return 0;
    }

    int num = 1;

    while (num <= SIZE) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (backtrack(board, row, col + 1)) {
                return 1;
            }
            board[row][col] = 0;
        }
        num++;
    }

    return 0;
}

int main() {
    int board[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }

    int row = 0;
    int col = 0;

    while (row < SIZE) {
        scanf("%d", &board[row][col]);
        col++;
        if (col == SIZE) {
            row++;
            col = 0;
        }
    }

    backtrack(board, 0, 0);

    print_board(board);

    return 0;
}