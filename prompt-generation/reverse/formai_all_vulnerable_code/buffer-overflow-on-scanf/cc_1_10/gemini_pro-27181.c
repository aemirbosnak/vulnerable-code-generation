//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Global variables */
int board[9][9], result[9][9], num_solutions;

/* Function prototypes */
int get_input(void);
int is_valid_move(int row, int col, int num);
int solve_sudoku(void);
void print_result(void);

int main(void) {
    /* Get the input from the user. */
    if (!get_input()) {
        printf("Invalid input.\n");
        return 1;
    }

    /* Solve the sudoku puzzle. */
    if (!solve_sudoku()) {
        printf("No solution found.\n");
        return 1;
    }

    /* Print the result. */
    print_result();

    return 0;
}

/* Get the input from the user. */
int get_input(void) {
    int i, j, num;

    printf("Enter the sudoku puzzle:\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d ", &num);
            if (num < 0 || num > 9) {
                return 0;
            }
            board[i][j] = num;
        }
    }

    return 1;
}

/* Check if a move is valid. */
int is_valid_move(int row, int col, int num) {
    int i, j;

    /* Check the row. */
    for (i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }

    /* Check the column. */
    for (i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }

    /* Check the 3x3 box. */
    int box_row = row / 3;
    int box_col = col / 3;
    for (i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (j = box_col * 3; j < box_col * 3 + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

/* Solve the sudoku puzzle. */
int solve_sudoku(void) {
    int i, j, k;

    /* Find an empty cell. */
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                /* Try all possible values for the cell. */
                for (k = 1; k <= 9; k++) {
                    if (is_valid_move(i, j, k)) {
                        /* Set the cell to the current value. */
                        board[i][j] = k;

                        /* Recursively solve the puzzle. */
                        if (solve_sudoku()) {
                            return 1;
                        }

                        /* If the puzzle is not solved, reset the cell to 0. */
                        board[i][j] = 0;
                    }
                }

                /* If no valid values were found for the cell, the puzzle is not solvable. */
                return 0;
            }
        }
    }

    /* If all cells are filled, the puzzle is solved. */
    return 1;
}

/* Print the result. */
void print_result(void) {
    int i, j;

    printf("The solution to the sudoku puzzle is:\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}