//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define N 9

int grid[N][N];

int is_valid(int row, int col, int val) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == val) {
            return 0;
        }
    }
    for (int j = 0; j < N; j++) {
        if (grid[j][col] == val) {
            return 0;
        }
    }
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
        for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
            if (grid[i][j] == val) {
                return 0;
            }
        }
    }
    return 1;
}

int solve() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                for (int val = 1; val <= N; val++) {
                    if (is_valid(row, col, val)) {
                        grid[row][col] = val;
                        if (solve()) {
                            return 1;
                        } else {
                            grid[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    printf("Enter the sudoku puzzle in the following format:\n");
    printf("0 for empty cells, 1-9 for filled cells:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (solve()) {
        printf("Solved Sudoku:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists\n");
    }

    return 0;
}