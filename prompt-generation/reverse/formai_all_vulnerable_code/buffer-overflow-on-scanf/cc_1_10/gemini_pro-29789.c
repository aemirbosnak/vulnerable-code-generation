//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

// The Sudoku board
int board[N][N];

// The possible values for each cell
int possibilities[N][N][N];

// A stack of cells to be checked
int stack[N*N];
int stack_size;

// A function to check if a value is possible for a cell
int is_possible(int row, int col, int value) {
    // Check the row
    for (int i = 0; i < N; i++) {
        if (board[row][i] == value) {
            return 0;
        }
    }

    // Check the column
    for (int i = 0; i < N; i++) {
        if (board[i][col] == value) {
            return 0;
        }
    }

    // Check the box
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[box_row*3+i][box_col*3+j] == value) {
                return 0;
            }
        }
    }

    // The value is possible
    return 1;
}

// A function to solve the Sudoku board
int solve() {
    // If the stack is empty, the board is solved
    if (stack_size == 0) {
        return 1;
    }

    // Get the next cell from the stack
    int row = stack[--stack_size];
    int col = stack[stack_size-1];

    // If the cell has a value, skip it
    if (board[row][col] != 0) {
        return solve();
    }

    // Try all possible values for the cell
    for (int value = 1; value <= N; value++) {
        // If the value is possible, set it and push the cell onto the stack
        if (is_possible(row, col, value)) {
            board[row][col] = value;
            stack[stack_size++] = row;
            stack[stack_size++] = col;

            // If the board is solved, return 1
            if (solve()) {
                return 1;
            }

            // If the board is not solved, reset the cell and pop the cell from the stack
            board[row][col] = 0;
            stack_size -= 2;
        }
    }

    // If no possible values for the cell, return 0
    return 0;
}

// A function to print the Sudoku board
void print_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// The main function
int main() {
    // Read the Sudoku board from the input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // Initialize the possibilities array
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                possibilities[i][j][k] = is_possible(i, j, k);
            }
        }
    }

    // Push the empty cells onto the stack
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                stack[stack_size++] = i;
                stack[stack_size++] = j;
            }
        }
    }

    // Solve the Sudoku board
    if (solve()) {
        // Print the solved board
        print_board();
    } else {
        // The board is unsolvable
        printf("The board is unsolvable\n");
    }

    return 0;
}