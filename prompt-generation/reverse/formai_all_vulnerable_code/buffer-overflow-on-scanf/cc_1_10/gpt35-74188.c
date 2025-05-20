//FormAI DATASET v1.0 Category: Sudoku solver ; Style: inquisitive
#include <stdio.h>

// Define Sudoku board size
#define BOARD_SIZE 9

// Function to print Sudoku board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a value can be placed in a certain cell
int is_valid(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int value) {
    // Check row
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == value) {
            return 0;
        }
    }

    // Check column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == value) {
            return 0;
        }
    }

    // Check 3x3 box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == value) {
                return 0;
            }
        }
    }

    // If all checks pass, the value can be placed in the cell
    return 1;
}

// Function to solve Sudoku using backtracking
int solve_sudoku(int board[BOARD_SIZE][BOARD_SIZE]) {
    int row = -1;
    int col = -1;
    int is_solved = 1;

    // Find an empty cell
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                is_solved = 0;
                break;
            }
        }
        if (!is_solved) {
            break;
        }
    }

    // If all cells are filled, the puzzle is solved
    if (is_solved) {
        return 1;
    }

    // Try different values in the empty cell
    for (int value = 1; value <= BOARD_SIZE; value++) {
        if (is_valid(board, row, col, value)) {
            board[row][col] = value;

            // Recursively try to solve the puzzle
            if (solve_sudoku(board)) {
                return 1;
            }

            // If the puzzle can't be solved with this value, backtrack
            board[row][col] = 0;
        }
    }

    // If no value can be placed in this cell, backtrack
    return 0;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Interact with the user to get input
    printf("Enter the Sudoku board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // Solve the Sudoku puzzle
    if (solve_sudoku(board)) {
        printf("The solution to the Sudoku puzzle:\n");
        print_board(board);
    }
    else {
        printf("The Sudoku puzzle can't be solved.\n");
    }

    return 0;
}