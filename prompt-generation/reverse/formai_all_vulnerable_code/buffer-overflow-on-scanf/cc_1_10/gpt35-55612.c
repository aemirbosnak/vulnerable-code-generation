//FormAI DATASET v1.0 Category: Sudoku solver ; Style: real-life
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 9

int grid[GRID_SIZE][GRID_SIZE] = {0};

bool is_valid(int row, int col, int num) {
    // Check row
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    // Check box
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;

    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solve() {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_valid(row, col, num)) {
                        grid[row][col] = num;

                        if (solve()) {
                            return true;
                        }

                        grid[row][col] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void print_grid() {
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            printf("%d ", grid[row][col]);
        }

        printf("\n");
    }
}

int main() {
    printf("Enter the initial grid:\n");

    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            scanf("%d", &grid[row][col]);
        }
    }

    if (solve()) {
        printf("Solution:\n");
        print_grid();
    } else {
        printf("No solution found.\n");
    }

    return 0;
}