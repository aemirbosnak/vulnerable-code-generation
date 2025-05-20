//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

int grid[N][N];
int row[N][N];
int col[N][N];
int box[N][N];

int solve(int);
int is_safe(int, int, int);
void print_grid(void);

int main(void) {
    int i, j;

    // Input the grid
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Initialize row, col and box arrays
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            row[i][j] = 0;
            col[i][j] = 0;
            box[i][j] = 0;
        }
    }

    // Set the row, col and box arrays
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (grid[i][j] != 0) {
                row[i][grid[i][j] - 1] = 1;
                col[j][grid[i][j] - 1] = 1;
                int box_index = (i / 3) * 3 + (j / 3);
                box[box_index][grid[i][j] - 1] = 1;
            }
        }
    }

    // Solve the grid
    if (solve(0)) {
        print_grid();
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}

int solve(int index) {
    int i, j, k;

    if (index == N * N) {
        return 1;
    }

    i = index / N;
    j = index % N;

    if (grid[i][j] != 0) {
        return solve(index + 1);
    }

    for (k = 0; k < N; k++) {
        if (is_safe(i, j, k)) {
            grid[i][j] = k + 1;
            row[i][k] = 1;
            col[j][k] = 1;
            int box_index = (i / 3) * 3 + (j / 3);
            box[box_index][k] = 1;
            if (solve(index + 1)) {
                return 1;
            } else {
                grid[i][j] = 0;
                row[i][k] = 0;
                col[j][k] = 0;
                box[box_index][k] = 0;
            }
        }
    }

    return 0;
}

int is_safe(int row, int col, int num) {
    int i, j;

    // Check row
    for (i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for (j = 0; j < N; j++) {
        if (grid[j][col] == num) {
            return 0;
        }
    }

    // Check box
    int box_index = (row / 3) * 3 + (col / 3);
    for (i = 0; i < N; i++) {
        if (grid[i / 3][i % 3] == num) {
            return 0;
        }
    }

    return 1;
}

void print_grid(void) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}