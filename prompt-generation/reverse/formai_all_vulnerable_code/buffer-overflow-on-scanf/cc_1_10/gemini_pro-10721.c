//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SUDOKU_SIZE 9
#define SUDOKU_BOX_SIZE 3

int sudoku[SUDOKU_SIZE][SUDOKU_SIZE];
bool solved = false;

void print_sudoku();
bool is_valid_move(int row, int col, int num);
void solve_sudoku(int row, int col);

int main() {
    // Get the input sudoku puzzle
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }

    // Print the input sudoku puzzle
    printf("Input Sudoku Puzzle:\n");
    print_sudoku();

    // Solve the sudoku puzzle
    solve_sudoku(0, 0);

    // Print the solved sudoku puzzle
    printf("Solved Sudoku Puzzle:\n");
    print_sudoku();

    return 0;
}

void print_sudoku() {
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        for (int j = 0; j < SUDOKU_SIZE; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

bool is_valid_move(int row, int col, int num) {
    // Check if the number is already present in the row
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        if (sudoku[row][i] == num) {
            return false;
        }
    }

    // Check if the number is already present in the column
    for (int i = 0; i < SUDOKU_SIZE; i++) {
        if (sudoku[i][col] == num) {
            return false;
        }
    }

    // Check if the number is already present in the box
    int box_row = row / SUDOKU_BOX_SIZE;
    int box_col = col / SUDOKU_BOX_SIZE;
    for (int i = box_row * SUDOKU_BOX_SIZE; i < box_row * SUDOKU_BOX_SIZE + SUDOKU_BOX_SIZE; i++) {
        for (int j = box_col * SUDOKU_BOX_SIZE; j < box_col * SUDOKU_BOX_SIZE + SUDOKU_BOX_SIZE; j++) {
            if (sudoku[i][j] == num) {
                return false;
            }
        }
    }

    // The number is valid to be placed in the cell
    return true;
}

void solve_sudoku(int row, int col) {
    // Check if the puzzle is already solved
    if (row == SUDOKU_SIZE && col == 0) {
        solved = true;
        return;
    }

    // Check if the current cell is already filled
    if (sudoku[row][col] != 0) {
        // Move to the next cell
        if (col == SUDOKU_SIZE - 1) {
            solve_sudoku(row + 1, 0);
        } else {
            solve_sudoku(row, col + 1);
        }
        return;
    }

    // Try all possible numbers for the current cell
    for (int num = 1; num <= SUDOKU_SIZE; num++) {
        if (is_valid_move(row, col, num)) {
            // Place the number in the cell
            sudoku[row][col] = num;

            // Move to the next cell
            if (col == SUDOKU_SIZE - 1) {
                solve_sudoku(row + 1, 0);
            } else {
                solve_sudoku(row, col + 1);
            }

            // If the puzzle is solved, break out of the loop
            if (solved) {
                break;
            }

            // If the puzzle is not solved, reset the cell to 0
            sudoku[row][col] = 0;
        }
    }
}