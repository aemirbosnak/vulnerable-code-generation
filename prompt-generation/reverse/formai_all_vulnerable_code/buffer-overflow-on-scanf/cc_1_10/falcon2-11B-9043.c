//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

typedef struct {
    int grid[MAX_SIZE][MAX_SIZE];
    int n;
} Sudoku;

void print_grid(Sudoku* sudoku) {
    for (int i = 0; i < sudoku->n; i++) {
        for (int j = 0; j < sudoku->n; j++) {
            printf("%d ", sudoku->grid[i][j]);
        }
        printf("\n");
    }
}

void solve_sudoku(Sudoku* sudoku) {
    // Initialize the grid with zeros
    for (int i = 0; i < sudoku->n; i++) {
        for (int j = 0; j < sudoku->n; j++) {
            sudoku->grid[i][j] = 0;
        }
    }

    // Find a cell with a value of 0
    for (int i = 0; i < sudoku->n; i++) {
        for (int j = 0; j < sudoku->n; j++) {
            if (sudoku->grid[i][j] == 0) {
                // Find a valid number for the cell
                for (int k = 1; k <= 9; k++) {
                    if (is_valid(sudoku, i, j, k)) {
                        sudoku->grid[i][j] = k;
                        solve_sudoku(sudoku);
                        if (is_solved(sudoku)) {
                            break;
                        }
                        sudoku->grid[i][j] = 0;
                    }
                }
                break;
            }
        }
        if (is_solved(sudoku)) {
            break;
        }
    }
}

int is_valid(Sudoku* sudoku, int i, int j, int num) {
    // Check if the number is valid in the current cell
    if (num > 0 && num <= 9) {
        for (int k = 0; k < sudoku->n; k++) {
            if (sudoku->grid[i][k] == num || sudoku->grid[k][j] == num) {
                return 0;
            }
        }

        // Check row and column
        for (int k = 0; k < sudoku->n; k++) {
            if (sudoku->grid[i][k] == num) {
                return 0;
            }
            if (sudoku->grid[k][j] == num) {
                return 0;
            }
        }

        // Check sub-grid
        int x = (i / 3) * 3;
        int y = (j / 3) * 3;
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (sudoku->grid[x + k][y + l] == num) {
                    return 0;
                }
            }
        }
        return 1;
    }
    return 0;
}

int is_solved(Sudoku* sudoku) {
    // Check if all cells are filled
    for (int i = 0; i < sudoku->n; i++) {
        for (int j = 0; j < sudoku->n; j++) {
            if (sudoku->grid[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    Sudoku sudoku;
    sudoku.n = MAX_SIZE;
    int num;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &(sudoku.n), &(sudoku.n));
    printf("Enter the grid values:\n");
    for (int i = 0; i < sudoku.n; i++) {
        for (int j = 0; j < sudoku.n; j++) {
            scanf("%d", &num);
            sudoku.grid[i][j] = num;
        }
    }
    solve_sudoku(&sudoku);
    print_grid(&sudoku);
    return 0;
}