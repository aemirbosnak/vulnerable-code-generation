//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 9
#define EMPTY 0
#define VALID_DIGITS (1 << 5)

// Function to print the Sudoku grid
void print_grid(int grid[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (grid[i][j] == EMPTY)
                printf(" ");
            else
                printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a digit is valid for a given row, column, and box
int is_valid(int grid[MAX_SIZE][MAX_SIZE], int row, int col, int num) {
    // Check row
    for (int i = 0; i < MAX_SIZE; i++) {
        if (grid[row][i] == num)
            return 0;
    }

    // Check column
    for (int j = 0; j < MAX_SIZE; j++) {
        if (grid[j][col] == num)
            return 0;
    }

    // Check box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + box_row][j + box_col] == num)
                return 0;
        }
    }

    return 1;
}

// Function to solve the Sudoku puzzle
int solve_sudoku(int grid[MAX_SIZE][MAX_SIZE]) {
    // Check if the puzzle is already solved
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (grid[i][j] == EMPTY)
                return 0;
        }
    }

    // Check if the puzzle is unsolvable
    int empty_count = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (grid[i][j] == EMPTY)
                empty_count++;
        }
    }
    if (empty_count!= 0)
        return 0;

    // Try all possible digits for the empty cells
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (grid[i][j] == EMPTY) {
                for (int num = 1; num <= 9; num++) {
                    if (is_valid(grid, i, j, num)) {
                        grid[i][j] = num;
                        if (solve_sudoku(grid))
                            return 1;
                        grid[i][j] = EMPTY;
                    }
                }
            }
        }
    }

    return 0;
}

// Main function
int main() {
    int grid[MAX_SIZE][MAX_SIZE] = {0};

    // Initialize the Sudoku puzzle with some values
    grid[0][0] = 5;
    grid[0][1] = 6;
    grid[0][2] = 7;
    grid[0][3] = 8;
    grid[0][4] = 9;
    grid[0][5] = 2;
    grid[0][6] = 3;
    grid[0][7] = 4;
    grid[0][8] = 1;
    grid[0][9] = 9;

    grid[1][0] = 6;
    grid[1][1] = 7;
    grid[1][2] = 8;
    grid[1][3] = 1;
    grid[1][4] = 9;
    grid[1][5] = 2;
    grid[1][6] = 3;
    grid[1][7] = 4;
    grid[1][8] = 5;
    grid[1][9] = 4;

    grid[2][0] = 7;
    grid[2][1] = 1;
    grid[2][2] = 9;
    grid[2][3] = 2;
    grid[2][4] = 8;
    grid[2][5] = 3;
    grid[2][6] = 4;
    grid[2][7] = 5;
    grid[2][8] = 6;
    grid[2][9] = 3;

    grid[3][0] = 8;
    grid[3][1] = 2;
    grid[3][2] = 3;
    grid[3][3] = 4;
    grid[3][4] = 5;
    grid[3][5] = 6;
    grid[3][6] = 7;
    grid[3][7] = 9;
    grid[3][8] = 1;
    grid[3][9] = 5;

    grid[4][0] = 9;
    grid[4][1] = 2;
    grid[4][2] = 1;
    grid[4][3] = 3;
    grid[4][4] = 4;
    grid[4][5] = 5;
    grid[4][6] = 6;
    grid[4][7] = 7;
    grid[4][8] = 8;
    grid[4][9] = 2;

    grid[5][0] = 2;
    grid[5][1] = 6;
    grid[5][2] = 7;
    grid[5][3] = 8;
    grid[5][4] = 9;
    grid[5][5] = 1;
    grid[5][6] = 3;
    grid[5][7] = 4;
    grid[5][8] = 5;
    grid[5][9] = 6;

    grid[6][0] = 3;
    grid[6][1] = 7;
    grid[6][2] = 8;
    grid[6][3] = 1;
    grid[6][4] = 2;
    grid[6][5] = 9;
    grid[6][6] = 4;
    grid[6][7] = 5;
    grid[6][8] = 6;
    grid[6][9] = 7;

    grid[7][0] = 4;
    grid[7][1] = 5;
    grid[7][2] = 6;
    grid[7][3] = 7;
    grid[7][4] = 8;
    grid[7][5] = 9;
    grid[7][6] = 1;
    grid[7][7] = 3;
    grid[7][8] = 2;
    grid[7][9] = 8;

    grid[8][0] = 5;
    grid[8][1] = 6;
    grid[8][2] = 7;
    grid[8][3] = 2;
    grid[8][4] = 3;
    grid[8][5] = 4;
    grid[8][6] = 5;
    grid[8][7] = 8;
    grid[8][8] = 9;
    grid[8][9] = 7;

    grid[9][0] = 6;
    grid[9][1] = 7;
    grid[9][2] = 8;
    grid[9][3] = 3;
    grid[9][4] = 4;
    grid[9][5] = 5;
    grid[9][6] = 6;
    grid[9][7] = 9;
    grid[9][8] = 1;
    grid[9][9] = 8;

    // Solve the Sudoku puzzle
    if (solve_sudoku(grid))
        print_grid(grid);
    else
        printf("Unsolvable!\n");

    return 0;
}