//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

// The Sudoku board
int board[N][N];

// The possible values for each cell
int possibilities[N][N][N];

// The number of possible values for each cell
int num_possibilities[N][N];

// The stack of cells to be checked
int stack[N * N];
int stack_top = 0;

// The number of solutions found
int solutions = 0;

// Function to print the Sudoku board
void print_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a cell is valid
int is_valid(int row, int col, int value) {
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

    // Check the 3x3 box
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
            if (board[i][j] == value) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to solve the Sudoku board
void solve_sudoku() {
    // Push the first cell onto the stack
    stack[stack_top++] = 0;

    while (stack_top > 0) {
        // Pop the top cell from the stack
        int cell = stack[--stack_top];

        // Get the row and column of the cell
        int row = cell / N;
        int col = cell % N;

        // If the cell is already filled in, skip it
        if (board[row][col] != 0) {
            continue;
        }

        // Try each possible value for the cell
        for (int value = 1; value <= N; value++) {
            // If the value is valid, set the cell to that value and push it onto the stack
            if (is_valid(row, col, value)) {
                board[row][col] = value;
                stack[stack_top++] = cell + 1;
                break;
            }
        }

        // If no valid value was found, backtrack by popping the cell from the stack
        if (stack_top == 0) {
            board[row][col] = 0;
        }
    }

    // Print the solution
    print_board();

    // Increment the number of solutions found
    solutions++;
}

int main() {
    // Get the input Sudoku board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // Calculate the possible values for each cell
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                for (int value = 1; value <= N; value++) {
                    if (is_valid(i, j, value)) {
                        possibilities[i][j][num_possibilities[i][j]++] = value;
                    }
                }
            }
        }
    }

    // Solve the Sudoku board
    solve_sudoku();

    // Print the number of solutions found
    printf("Number of solutions: %d", solutions);

    return 0;
}