//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

int grid[N][N];

int is_valid(int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
        if (grid[i][col] == num) {
            return 0;
        }
    }

    int box_row = row / 3;
    int box_col = col / 3;

    for (int i = 3*box_row; i < 3*box_row + 3; i++) {
        for (int j = 3*box_col; j < 3*box_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku(int row, int col) {
    if (row == N - 1 && col == N) {
        return 1;
    }

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] != 0) {
        return solve_sudoku(row, col + 1);
    }

    for (int num = 1; num <= N; num++) {
        if (is_valid(row, col, num)) {
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
    memset(grid, 0, sizeof(grid));

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, y, num;
        scanf("%d %d %d", &x, &y, &num);
        grid[x][y] = num;
    }

    if (solve_sudoku(0, 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found\n");
    }

    return 0;
}