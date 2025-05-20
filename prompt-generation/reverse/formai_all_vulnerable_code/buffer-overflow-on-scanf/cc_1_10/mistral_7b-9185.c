//MISTRAL-7B DATASET v1.0 Category: Sudoku solver ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

void print_board(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
            if (j < N - 1)
                printf("|");
        }
        printf("\n");
        if (i < N - 1) {
            for (int j = 0; j < N; j++) {
                printf("-+");
                if (j < N - 1)
                    printf("--");
                printf("+");
            }
            printf("\n");
        }
    }
}

bool is_valid(int board[N][N], int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num)
            return false;
        if (board[i][col] == num)
            return false;
    }

    int box_row = row - row % 3, box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool sudoku_solver(int board[N][N], int row, int col) {
    if (col == N)
        return sudoku_solver(board, row + 1, 0);

    if (board[row][col] != 0)
        return sudoku_solver(board, row, col + 1);

    for (int num = 1; num <= N; num++) {
        if (is_valid(board, row, col, num)) {
            board[row][col] = num;
            if (sudoku_solver(board, row, col + 1))
                return true;
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int board[N][N];
    int row = 0, col = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 0) {
                row = i;
                col = j;
            }
        }
    }

    if (sudoku_solver(board, 0, 0))
        print_board(board);
    else
        printf("No solution found.\n");

    return 0;
}