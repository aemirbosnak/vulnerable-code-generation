//FormAI DATASET v1.0 Category: Sudoku solver ; Style: excited
#include <stdio.h>

/* A thrilling Sudoku solver program using backtracking! */

#define N 9  // size of the grid.

void initialize_board(int grid[][N]) {
    // Initialize the board with user input.
    puts("Enter the Sudoku puzzle (use 0 for missing number): ");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    puts("");
}

void print_board(int grid[][N]) {
    // Print the populated Sudoku board.
    puts("Sudoku Puzzle:");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
            if ((j + 1) % 3 == 0 && j != N - 1) printf("| ");
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i != N - 1) printf("---------------------\n");
    }
    puts("");
}

int is_possible(int grid[][N], int row, int col, int num) {
    // Check if the given number is possible in given cell.
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;
    }
    int box_row = (row / 3) * 3, box_col = (col / 3) * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (grid[i][j] == num) return 0;
        }
    }
    return 1;
}

int is_empty_cell(int grid[][N], int *row, int *col) {
    // Find the next empty cell in the grid.
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) return 1;
        }
    }
    return 0;
}

int solve_sudoku(int grid[][N]) {
    // Solve the Sudoku puzzle recursively using backtracking.
    int row, col;
    if (!is_empty_cell(grid, &row, &col)) return 1;

    for (int i = 1; i <= N; i++) {
        if (is_possible(grid, row, col, i)) {
            grid[row][col] = i;

            if (solve_sudoku(grid)) return 1;

            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    puts("Welcome to the Ultimate Sudoku Solver!\n");
    int grid[N][N] = {0};

    initialize_board(grid);
    print_board(grid);

    if (solve_sudoku(grid)) {
        puts("Solution:");
        print_board(grid);
    } else {
        puts("No solution exists!");
    }

    return 0;
}