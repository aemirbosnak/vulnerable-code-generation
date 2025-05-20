//FormAI DATASET v1.0 Category: Sudoku solver ; Style: peaceful
#include <stdio.h>

#define N 9
#define UNASSIGNED 0

int grid[N][N];

int find_empty_cell(int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED) {
                return 1;
            }
        }
    }
    return 0;
}

int is_valid(int row, int col, int digit) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == digit || grid[i][col] == digit) {
            return 0;
        }
    }
    int start_row = row - row % 3, start_col = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[start_row + i][start_col + j] == digit) {
                return 0;
            }
        }
    }
    return 1;
}

int solve() {
    int row, col;
    if (!find_empty_cell(&row, &col)) {
        return 1;
    }
    for (int digit = 1; digit <= N; digit++) {
        if (is_valid(row, col, digit)) {
            grid[row][col] = digit;
            if (solve()) {
                return 1;
            }
            grid[row][col] = UNASSIGNED;
        }
    }
    return 0;
}

void print_solution() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the Sudoku grid (use 0 for empty cells):\n");
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            scanf("%d", &grid[row][col]);
        }
    }
    if (solve()) {
        printf("\nSolution:\n");
        print_solution();
    } else {
        printf("\nNo solution exists.");
    }
    return 0;
}