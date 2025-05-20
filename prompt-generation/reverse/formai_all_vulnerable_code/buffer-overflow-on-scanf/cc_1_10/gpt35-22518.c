//FormAI DATASET v1.0 Category: Sudoku solver ; Style: dynamic
#include <stdio.h>

#define GRID_SIZE 9

int grid[GRID_SIZE][GRID_SIZE];

int is_valid(int row, int col, int value) {
    // Check if value is already present in row or col
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == value || grid[i][col] == value) {
            return 0;
        }
    }
    // Check if value is already present in 3x3 sub-grid
    int subgrid_row = row - row % 3;
    int subgrid_col = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[subgrid_row + i][subgrid_col + j] == value) {
                return 0;
            }
        }
    }
    return 1;
}

int solve(int row, int col) {
    // If we've reached the end of the grid, it means that
    // we have successfully solved the Sudoku
    if (row == GRID_SIZE) {
        return 1;
    }
    int next_row = row;
    int next_col = col + 1;
    // If we've reached the end of a row, go to the next row
    if (next_col == GRID_SIZE) {
        next_row++;
        next_col = 0;
    }
    // If this cell is already filled, move on to the next cell
    if (grid[row][col] != 0) {
        return solve(next_row, next_col);
    }
    // Try out all possible values for this cell
    for (int i = 1; i <= 9; i++) {
        if (is_valid(row, col, i)) {
            grid[row][col] = i;
            if (solve(next_row, next_col)) {
                // If a solution is found, return 1
                return 1;
            }
            // If this value doesn't lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }
    // If none of the values we tried for this cell lead to a solution,
    // backtrack to the previous cell
    return 0;
}

void print_grid() {
    printf("-------------\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("|");
        for (int j = 0; j < GRID_SIZE; j++) {
            printf(" %d ", grid[i][j]);
            if ((j + 1) % 3 == 0) {
                printf("|");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("-------------\n");
        }
    }
}

int main() {
    printf("Enter the Sudoku puzzle (with 0s for empty cells):\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    if (solve(0, 0)) {
        printf("Solution found:\n");
        print_grid();
    } else {
        printf("No solution found\n");
    }
    return 0;
}