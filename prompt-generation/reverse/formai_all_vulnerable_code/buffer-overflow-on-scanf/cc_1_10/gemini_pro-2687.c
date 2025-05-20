//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 9

// Check if the given number is valid in the given row, column, and box.
int is_valid(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int num) {
    // Check the row.
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }

    // Check the column.
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }

    // Check the box.
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
        for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    // The number is valid.
    return 1;
}

// Solve the Sudoku puzzle using backtracking.
int solve_sudoku(int board[BOARD_SIZE][BOARD_SIZE]) {
    // Find the first empty cell.
    int row, col;
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == 0) {
                goto found;
            }
        }
    }

  found:

    // If there are no empty cells, the puzzle is solved.
    if (row == BOARD_SIZE) {
        return 1;
    }

    // Try all possible values for the empty cell.
    for (int num = 1; num <= BOARD_SIZE; num++) {
        // Check if the value is valid.
        if (is_valid(board, row, col, num)) {
            // Set the value and recursively solve the puzzle.
            board[row][col] = num;
            if (solve_sudoku(board)) {
                return 1;
            }
            // If the puzzle is not solved, reset the value.
            board[row][col] = 0;
        }
    }

    // No solution found for this cell.
    return 0;
}

// Print the Sudoku puzzle.
void print_sudoku(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

int main() {
    // Get the input Sudoku puzzle.
    int board[BOARD_SIZE][BOARD_SIZE];
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            scanf("%d ", &board[row][col]);
        }
    }

    // Solve the puzzle.
    if (solve_sudoku(board)) {
        printf("The solved Sudoku puzzle is:\n");
        print_sudoku(board);
    } else {
        printf("No solution found for the given Sudoku puzzle.\n");
    }

    return 0;
}