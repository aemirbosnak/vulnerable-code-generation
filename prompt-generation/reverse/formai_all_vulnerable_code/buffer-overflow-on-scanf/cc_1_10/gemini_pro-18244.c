//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define N 9

int grid[N][N];

int is_safe(int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve_sudoku(int row, int col) {
    if (row == N) {
        return 1;
    }
    if (col == N) {
        return solve_sudoku(row + 1, 0);
    }
    if (grid[row][col] != 0) {
        return solve_sudoku(row, col + 1);
    }
    for (int num = 1; num <= N; num++) {
        if (is_safe(row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(row, col + 1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    if (solve_sudoku(0, 0)) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists\n");
    }
    return 0;
}