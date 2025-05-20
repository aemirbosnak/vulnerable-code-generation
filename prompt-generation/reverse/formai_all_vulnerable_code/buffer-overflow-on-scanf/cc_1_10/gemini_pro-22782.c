//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define N 9

int grid[N][N];
int rows[N][N + 1];
int cols[N][N + 1];
int boxes[N][N + 1];

int find_empty_cell(int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int is_valid(int row, int col, int val) {
    return !rows[row][val] && !cols[col][val] && !boxes[row - row % 3 + col / 3][val];
}

int solve_sudoku() {
    int row, col;
    if (!find_empty_cell(&row, &col)) {
        return 1;
    }

    for (int val = 1; val <= N; val++) {
        if (is_valid(row, col, val)) {
            grid[row][col] = val;
            rows[row][val] = 1;
            cols[col][val] = 1;
            boxes[row - row % 3 + col / 3][val] = 1;

            if (solve_sudoku()) {
                return 1;
            }

            grid[row][col] = 0;
            rows[row][val] = 0;
            cols[col][val] = 0;
            boxes[row - row % 3 + col / 3][val] = 0;
        }
    }
    return 0;
}

void print_sudoku() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
            rows[i][grid[i][j]] = 1;
            cols[j][grid[i][j]] = 1;
            boxes[i - i % 3 + j / 3][grid[i][j]] = 1;
        }
    }

    if (solve_sudoku()) {
        print_sudoku();
    } else {
        printf("No solution exists\n");
    }

    return 0;
}