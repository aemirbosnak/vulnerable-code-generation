//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int grid[9][9];
int solved = 0;

int is_safe(int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }

    int box_row = row / 3;
    int box_col = col / 3;

    for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

void solve_sudoku() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_safe(row, col, num)) {
                        grid[row][col] = num;
                        solve_sudoku();
                        if (solved) {
                            return;
                        } else {
                            grid[row][col] = 0;
                        }
                    }
                }
                return;
            }
        }
    }

    solved = 1;
}

void print_sudoku() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of filled cells: ");
    scanf("%d", &n);

    printf("Enter the coordinates and values of the filled cells: ");
    for (int i = 0; i < n; i++) {
        int row, col, val;
        scanf("%d %d %d", &row, &col, &val);
        grid[row - 1][col - 1] = val;
    }

    solve_sudoku();

    if (solved) {
        printf("Solved Sudoku:\n");
        print_sudoku();
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}