//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define N 9

int grid[N][N];
int solved = 0;

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
    for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
        for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

void solve(int row, int col) {
    if (row == N) {
        solved = 1;
        return;
    }

    if (col == N) {
        solve(row + 1, 0);
        return;
    }

    if (grid[row][col] != 0) {
        solve(row, col + 1);
        return;
    }

    for (int num = 1; num <= N; num++) {
        if (is_valid(row, col, num)) {
            grid[row][col] = num;
            solve(row, col + 1);
            grid[row][col] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    solve(0, 0);

    if (solved) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.");
    }

    return 0;
}