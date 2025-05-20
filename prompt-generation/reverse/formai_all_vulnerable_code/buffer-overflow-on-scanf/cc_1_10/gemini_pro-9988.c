//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 9

// Function to print the Sudoku board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the given number is safe to place in the given cell
bool is_safe(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int num) {
    // Check the row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    // Check the column
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[j][col] == num) {
            return false;
        }
    }

    // Check the 3x3 subgrid
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
        for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    // If all checks pass, the number is safe to place
    return true;
}

// Recursive function to solve the Sudoku board
bool solve_sudoku(int board[BOARD_SIZE][BOARD_SIZE]) {
    // Find the first empty cell
    int row, col;
    for (row = 0; row < BOARD_SIZE; row++) {
        for (col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == 0) {
                goto found;
            }
        }
    }
    // If no empty cell is found, the board is solved
    return true;

found:
    // Try all possible numbers for the empty cell
    for (int num = 1; num <= BOARD_SIZE; num++) {
        // If the number is safe to place, place it and recursively solve the rest of the board
        if (is_safe(board, row, col, num)) {
            board[row][col] = num;
            if (solve_sudoku(board)) {
                return true;
            } else {
                // If the recursive call fails, reset the cell to 0 and try the next number
                board[row][col] = 0;
            }
        }
    }

    // If no safe number can be placed, the board cannot be solved
    return false;
}

// Main function to read the Sudoku board from the user and solve it
int main() {
    // Read the Sudoku board from the user
    int board[BOARD_SIZE][BOARD_SIZE];
    printf("Enter the Sudoku board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // Solve the Sudoku board
    if (solve_sudoku(board)) {
        // Print the solved board
        printf("The solved Sudoku board is:\n");
        print_board(board);
    } else {
        // No solution exists
        printf("No solution exists for the given Sudoku board.\n");
    }

    return 0;
}