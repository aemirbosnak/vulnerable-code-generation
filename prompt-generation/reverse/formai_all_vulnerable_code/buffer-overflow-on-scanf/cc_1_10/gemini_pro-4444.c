//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_SIZE 9

typedef struct {
    int grid[GRID_SIZE][GRID_SIZE];
    int solved;
} Sudoku;

Sudoku* create_sudoku() {
    Sudoku* sudoku = malloc(sizeof(Sudoku));
    memset(sudoku->grid, 0, sizeof(sudoku->grid));
    sudoku->solved = 0;
    return sudoku;
}

void destroy_sudoku(Sudoku* sudoku) {
    free(sudoku);
}

int is_valid_move(Sudoku* sudoku, int row, int col, int value) {
    // Check if the value is already present in the row
    for (int i = 0; i < GRID_SIZE; i++) {
        if (sudoku->grid[row][i] == value) {
            return 0;
        }
    }

    // Check if the value is already present in the column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (sudoku->grid[i][col] == value) {
            return 0;
        }
    }

    // Check if the value is already present in the 3x3 subgrid
    int subgrid_row = row / 3;
    int subgrid_col = col / 3;
    for (int i = subgrid_row * 3; i < subgrid_row * 3 + 3; i++) {
        for (int j = subgrid_col * 3; j < subgrid_col * 3 + 3; j++) {
            if (sudoku->grid[i][j] == value) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku(Sudoku* sudoku, int row, int col) {
    // If we have reached the end of the grid, the sudoku is solved
    if (row == GRID_SIZE) {
        sudoku->solved = 1;
        return 1;
    }

    // If the current cell is already filled, move to the next cell
    if (sudoku->grid[row][col] != 0) {
        return solve_sudoku(sudoku, row + (col + 1) / GRID_SIZE, (col + 1) % GRID_SIZE);
    }

    // Try all possible values for the current cell
    for (int value = 1; value <= GRID_SIZE; value++) {
        if (is_valid_move(sudoku, row, col, value)) {
            sudoku->grid[row][col] = value;
            if (solve_sudoku(sudoku, row + (col + 1) / GRID_SIZE, (col + 1) % GRID_SIZE)) {
                return 1;
            }
            sudoku->grid[row][col] = 0;
        }
    }

    return 0;
}

void print_sudoku(Sudoku* sudoku) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", sudoku->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Sudoku* sudoku = create_sudoku();

    // Get the input sudoku grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            scanf("%d", &sudoku->grid[i][j]);
        }
    }

    // Solve the sudoku
    solve_sudoku(sudoku, 0, 0);

    // Print the solved sudoku
    if (sudoku->solved) {
        print_sudoku(sudoku);
    } else {
        printf("No solution found.\n");
    }

    destroy_sudoku(sudoku);

    return 0;
}