//FormAI DATASET v1.0 Category: Sudoku solver ; Style: creative
#include <stdio.h>

int grid[9][9];

int check_row(int row, int num) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return 1;
        }
    }
    return 0;
}

int check_col(int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return 1;
        }
    }
    return 0;
}

int check_square(int row, int col, int num) {
    int row_start = row - (row % 3);
    int col_start = col - (col % 3);

    for (int i = row_start; i < row_start + 3; i++) {
        for (int j = col_start; j < col_start + 3; j++) {
            if (grid[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int is_safe(int row, int col, int num) {
    return !check_row(row, num) && !check_col(col, num) && !check_square(row, col, num);
}

int find_empty_cell(int *row, int *col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int solve_sudoku() {
    int row, col;

    if (!find_empty_cell(&row, &col)) {
        return 1;
    }

    for (int num = 1; num <= 9; num++) {
        if (is_safe(row, col, num)) {
            grid[row][col] = num;

            if (solve_sudoku()) {
                return 1;
            }

            grid[row][col] = 0;
        }
    }

    return 0;
}

int main() {
    printf("Enter the sudoku puzzle line by line (enter 0 for empty cells):\n");

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (solve_sudoku()) {
        printf("Solution:\n");

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}