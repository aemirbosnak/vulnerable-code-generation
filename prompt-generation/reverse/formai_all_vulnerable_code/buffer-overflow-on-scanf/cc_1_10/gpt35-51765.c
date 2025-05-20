//FormAI DATASET v1.0 Category: Sudoku solver ; Style: mathematical
#include <stdio.h>

#define SIZE 9

int grid[SIZE][SIZE];

int is_row_valid(int row, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }
    return 1;
}

int is_col_valid(int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

int is_box_valid(int start_row, int start_col, int num) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[start_row + i][start_col + j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int is_valid(int row, int col, int num) {
    return is_row_valid(row, num) && is_col_valid(col, num) && is_box_valid(row - row % 3, col - col % 3, num);
}

int solve_sudoku() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_valid(row, col, num)) {
                        grid[row][col] = num;
                        if (solve_sudoku()) {
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

void print_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Input sudoku puzzle
    printf("Enter values (0 for empty cells):\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Solve the puzzle
    if (solve_sudoku()) {
        printf("Solution found:\n");
        print_grid();
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}