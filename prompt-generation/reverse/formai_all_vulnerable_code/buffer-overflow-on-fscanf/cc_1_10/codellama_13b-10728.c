//Code Llama-13B DATASET v1.0 Category: Sudoku solver ; Style: grateful
/*
 * A unique C Sudoku solver example program in a grateful style
 *
 * Usage:
 *   $ ./sudoku-solver <filename>
 *
 * Example:
 *   $ ./sudoku-solver example.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 9
#define ROW_SIZE 3
#define COL_SIZE 3

typedef struct {
    int row;
    int col;
    int value;
} cell_t;

typedef struct {
    cell_t cells[GRID_SIZE][GRID_SIZE];
    int row_size;
    int col_size;
    int grid_size;
} sudoku_grid_t;

// Check if a cell is already filled with a value
int cell_filled(sudoku_grid_t *grid, int row, int col) {
    return grid->cells[row][col].value != 0;
}

// Check if a value is valid for a cell
int value_valid(sudoku_grid_t *grid, int row, int col, int value) {
    int row_start = (row / ROW_SIZE) * ROW_SIZE;
    int row_end = row_start + ROW_SIZE;
    int col_start = (col / COL_SIZE) * COL_SIZE;
    int col_end = col_start + COL_SIZE;

    // Check row
    for (int i = row_start; i < row_end; i++) {
        if (grid->cells[i][col].value == value) {
            return 0;
        }
    }

    // Check column
    for (int i = col_start; i < col_end; i++) {
        if (grid->cells[row][i].value == value) {
            return 0;
        }
    }

    // Check 3x3 sub-grid
    for (int i = row_start; i < row_end; i++) {
        for (int j = col_start; j < col_end; j++) {
            if (grid->cells[i][j].value == value) {
                return 0;
            }
        }
    }

    return 1;
}

// Fill a cell with a value
void fill_cell(sudoku_grid_t *grid, int row, int col, int value) {
    grid->cells[row][col].value = value;
}

// Solve a sudoku grid
void solve_grid(sudoku_grid_t *grid) {
    // Find an empty cell
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (!cell_filled(grid, i, j)) {
                // Try each value from 1 to 9
                for (int k = 1; k <= 9; k++) {
                    if (value_valid(grid, i, j, k)) {
                        fill_cell(grid, i, j, k);
                        solve_grid(grid);
                        fill_cell(grid, i, j, 0);
                    }
                }
                return;
            }
        }
    }

    // If all cells are filled, the grid is solved
    printf("Solved!\n");
}

int main(int argc, char *argv[]) {
    // Load the sudoku grid from a file
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    sudoku_grid_t grid;
    memset(&grid, 0, sizeof(grid));

    int row = 0;
    int col = 0;

    while (fscanf(fp, "%d", &grid.cells[row][col].value) == 1) {
        col++;
        if (col == GRID_SIZE) {
            col = 0;
            row++;
        }
    }

    fclose(fp);

    // Solve the sudoku grid
    solve_grid(&grid);

    return 0;
}