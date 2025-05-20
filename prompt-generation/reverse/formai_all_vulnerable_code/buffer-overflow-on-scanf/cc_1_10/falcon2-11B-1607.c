//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int is_safe(int board[9][9], int row, int col, int num) {
    int i, j;

    for (i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return 0;
    }

    for (i = 0; i < 9; i++) {
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            return 0;
    }

    for (j = 0; j < 9; j++) {
        if (board[j][3 * (col / 3) + i % 3] == num)
            return 0;
    }

    return 1;
}

int solve_sudoku(int board[9][9]) {
    int row, col;
    int num;

    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                num = 1;
                while (is_safe(board, row, col, num)) {
                    board[row][col] = num;
                    num++;
                }

                if (num > 9)
                    return 0;
            }
        }
    }

    return 1;
}

int main() {
    int board[9][9];

    printf("Enter the board:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
        printf("\n");
    }

    if (solve_sudoku(board)) {
        printf("Solution:\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution\n");
    }

    return 0;
}