//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: irregular
// A Sudoku solver in pure C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The Sudoku board
int board[9][9];

// The number of solutions found
int solutions = 0;

// The stack of possible values for each cell
int stack[9][9][9];

// The top of the stack for each cell
int top[9][9];

// Check if a value is valid in a cell
int valid(int row, int col, int val) {
    // Check the row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == val) {
            return 0;
        }
    }

    // Check the column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == val) {
            return 0;
        }
    }

    // Check the box
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[box_row * 3 + i][box_col * 3 + j] == val) {
                return 0;
            }
        }
    }

    // The value is valid
    return 1;
}

// Push a value onto the stack
void push(int row, int col, int val) {
    stack[row][col][top[row][col]] = val;
    top[row][col]++;
}

// Pop a value from the stack
int pop(int row, int col) {
    top[row][col]--;
    return stack[row][col][top[row][col]];
}

// Solve the Sudoku puzzle
void solve() {
    // Try all possible values for the first empty cell
    int row = -1, col = -1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                break;
            }
        }
    }

    if (row == -1) {
        // No empty cells left, the puzzle is solved
        solutions++;
        return;
    }

    for (int val = 1; val <= 9; val++) {
        if (valid(row, col, val)) {
            // The value is valid, so push it onto the stack and try to solve the rest of the puzzle
            push(row, col, val);
            board[row][col] = val;
            solve();
            board[row][col] = 0;
            pop(row, col);
        }
    }
}

// Print the Sudoku board
void print_board() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Read the Sudoku puzzle from the input
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d ", &board[i][j]);
        }
    }

    // Solve the puzzle
    solve();

    // Print the solusi
    if (solutions == 1) {
        printf("Solution:\n");
        print_board();
    } else {
        printf("No solusi found.\n");
    }

    return 0;
}