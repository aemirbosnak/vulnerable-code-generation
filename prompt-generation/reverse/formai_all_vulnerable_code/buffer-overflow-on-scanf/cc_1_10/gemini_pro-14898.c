//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 9
#define FAILED 0
#define SUCCEEDED 1

int grid[DIM * DIM];
int row_used[DIM][DIM];
int col_used[DIM][DIM];
int box_used[DIM][DIM];

int get_box_index(int row, int col) {
    return (row / 3) * 3 + (col / 3);
}

int is_safe(int row, int col, int val) {
    return !(row_used[row][val - 1] || col_used[col][val - 1] || box_used[get_box_index(row, col)][val - 1]);
}

int solve_sudoku() {
    int row, col;
    for (row = 0; row < DIM; row++) {
        for (col = 0; col < DIM; col++) {
            if (!grid[row * DIM + col]) {
                for (int val = 1; val <= DIM; val++) {
                    if (is_safe(row, col, val)) {
                        grid[row * DIM + col] = val;
                        row_used[row][val - 1] = 1;
                        col_used[col][val - 1] = 1;
                        box_used[get_box_index(row, col)][val - 1] = 1;
                        if (solve_sudoku()) {
                            return SUCCEEDED;
                        }
                        grid[row * DIM + col] = 0;
                        row_used[row][val - 1] = 0;
                        col_used[col][val - 1] = 0;
                        box_used[get_box_index(row, col)][val - 1] = 0;
                    }
                }
                return FAILED;
            }
        }
    }
    return SUCCEEDED;
}

void print_grid() {
    for (int row = 0; row < DIM; row++) {
        for (int col = 0; col < DIM; col++) {
            printf("%d ", grid[row * DIM + col]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize grid with user input
    for (int i = 0; i < DIM * DIM; i++) {
        scanf("%d", &grid[i]);
    }

    // Set used flags to 0
    memset(row_used, 0, sizeof(row_used));
    memset(col_used, 0, sizeof(col_used));
    memset(box_used, 0, sizeof(box_used));

    // Solve the sudoku
    if (solve_sudoku()) {
        print_grid();
    } else {
        printf("No solution found!\n");
    }

    return 0;
}