//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: mind-bending
#include <stdio.h>
#define N 9
#define SQRT_N 3
#define EMPTY 0

int grid[N][N];

int is_safe(int row, int col, int val) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == val || grid[i][col] == val) {
            return 0;
        }
    }

    int box_row = row / SQRT_N;
    int box_col = col / SQRT_N;
    for (int i = box_row * SQRT_N; i < box_row * SQRT_N + SQRT_N; i++) {
        for (int j = box_col * SQRT_N; j < box_col * SQRT_N + SQRT_N; j++) {
            if (grid[i][j] == val) {
                return 0;
            }
        }
    }

    return 1;
}

int solve() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == EMPTY) {
                for (int k = 1; k <= N; k++) {
                    if (is_safe(i, j, k)) {
                        grid[i][j] = k;
                        if (solve()) {
                            return 1;
                        }
                        grid[i][j] = EMPTY;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int i, j;
    printf("Enter the Sudoku grid: \n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (solve()) {
        printf("The solution to the Sudoku grid is: \n");
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists for the given Sudoku grid.\n");
    }

    return 0;
}