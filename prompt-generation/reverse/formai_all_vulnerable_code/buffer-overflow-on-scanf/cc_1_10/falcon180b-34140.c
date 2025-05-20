//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
/* C Sudoku Solver Example Program in a Dennis Ritchie style */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9
#define MAX_ROWS 9
#define MAX_COLS 9
#define MAX_VAL 9

/* Function to print the Sudoku board */
void printBoard(int board[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

/* Function to check if a value is valid in a given row, column or box */
int isValid(int board[MAX_ROWS][MAX_COLS], int row, int col, int value) {
    int i, j;

    /* Check row */
    for (i = 0; i < MAX_ROWS; i++) {
        if (board[row][i] == value) {
            return 0;
        }
    }

    /* Check column */
    for (i = 0; i < MAX_ROWS; i++) {
        if (board[i][col] == value) {
            return 0;
        }
    }

    /* Check box */
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (i = boxRow; i < boxRow + 3; i++) {
        for (j = boxCol; j < boxCol + 3; j++) {
            if (board[i][j] == value) {
                return 0;
            }
        }
    }

    return 1;
}

/* Function to solve the Sudoku board using backtracking algorithm */
int solveBoard(int board[MAX_ROWS][MAX_COLS]) {
    int i, j, found = 0;

    /* Check if the board is already solved */
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }

    /* Try all possible values for empty cells */
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (board[i][j] == 0) {
                for (int value = 1; value <= MAX_VAL; value++) {
                    if (isValid(board, i, j, value)) {
                        board[i][j] = value;

                        /* Check if the board is solved */
                        if (solveBoard(board)) {
                            return 1;
                        }

                        /* Backtrack if the current value is not valid */
                        board[i][j] = 0;
                    }
                }
                return 0;
            }
        }
    }

    return 1;
}

/* Main function to read the Sudoku board from input and solve it */
int main() {
    int board[MAX_ROWS][MAX_COLS];
    int i, j;

    /* Read the Sudoku board from input */
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    /* Solve the Sudoku board */
    if (solveBoard(board)) {
        printBoard(board);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}

/* End of C Sudoku Solver Example Program */