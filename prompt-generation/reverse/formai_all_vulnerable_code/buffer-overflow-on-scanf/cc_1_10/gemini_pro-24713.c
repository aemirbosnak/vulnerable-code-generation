//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 9
#define EMPTY -1

int board[BOARD_SIZE][BOARD_SIZE];

int is_valid_move(int row, int col, int num) {
    // Check row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }

    // Check box
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku() {
    // Find an empty cell
    int row, col;
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == EMPTY) {
                goto found;
            }
        }
    }

    // No empty cells, sudoku is solved
    return 1;

found:

    // Try numbers 1-9
    for (int num = 1; num <= BOARD_SIZE; num++) {
        if (is_valid_move(row, col, num)) {
            // Place the number in the cell
            board[row][col] = num;

            // Recursively solve the rest of the sudoku
            if (solve_sudoku()) {
                return 1;
            } else {
                // Backtrack: remove the number from the cell
                board[row][col] = EMPTY;
            }
        }
    }

    // No valid moves, return failure
    return 0;
}

int main() {
    // Get the sudoku puzzle from the user
    printf("Enter the sudoku puzzle, use -1 for empty cells:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            scanf("%d ", &board[i][j]);
        }
    }

    // Solve the sudoku
    if (solve_sudoku()) {
        // Print the solved sudoku
        printf("Solved sudoku:\n");
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}