//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define N 9

int board[N][N] = {{0}};

void print_board() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void set_value(int row, int col, int value) {
    if (row >= 0 && row < N && col >= 0 && col < N) {
        board[row][col] = value;
    }
}

int is_valid(int row, int col, int value) {
    int i, j;

    // Check row
    for (i = 0; i < N; i++) {
        if (board[row][i] == value) {
            return 0;
        }
    }

    // Check column
    for (i = 0; i < N; i++) {
        if (board[i][col] == value) {
            return 0;
        }
    }

    // Check 3x3 box
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (i = box_row; i < box_row + 3; i++) {
        for (j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == value) {
                return 0;
            }
        }
    }

    return 1;
}

void solve() {
    int i, j;

    // Fill in any missing values
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                int value = 1;
                while (!is_valid(i, j, value)) {
                    value++;
                }
                set_value(i, j, value);
            }
        }
    }

    // Print solution
    print_board();
}

int main() {
    int i, j;

    // Read in initial board
    printf("Enter the initial board:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // Solve Sudoku
    solve();

    return 0;
}