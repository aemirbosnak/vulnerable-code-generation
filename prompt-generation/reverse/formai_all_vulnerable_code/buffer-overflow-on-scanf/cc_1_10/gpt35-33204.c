//FormAI DATASET v1.0 Category: Sudoku solver ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define UNASSIGNED 0
#define N 9

int grid[N][N];

int check_row(int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

int check_column(int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

int check_box(int start_row, int start_col, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[start_row + row][start_col + col] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int is_safe(int row, int col, int num) {
    return !check_row(row, num) && !check_column(col, num) && !check_box(row - row % 3, col - col % 3, num);
}

int find_unassigned_location(int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED) {
                return 1;
            }
        }
    }
    return 0;
}

int solve_sudoku() {
    int row, col;
    if (!find_unassigned_location(&row, &col)) {
        return 1;
    }
    for (int num = 1; num <= 9; num++) {
        if (is_safe(row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku()) {
                return 1;
            }
            grid[row][col] = UNASSIGNED;
        }
    }
    return 0;
}

void print_grid() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            scanf("%d", &grid[row][col]);
        }
    }

    if (solve_sudoku()) {
        printf("Sudoku solved successfully!\n\n");
        print_grid();
    } else {
        printf("Sudoku cannot be solved!\n");
    }

    return 0;
}