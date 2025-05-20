//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

// The Sudoku board
int board[SIZE][SIZE];

// Function to print the Sudoku board
void print_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is safe to place in a cell
bool is_safe(int row, int col, int num) {
    // Check the row
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    // Check the column
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // Check the box
    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = 3 * box_row; i < 3 * box_row + 3; i++) {
        for (int j = 3 * box_col; j < 3 * box_col + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku board
bool solve() {
    // Find an empty cell
    int row, col;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                goto found;
            }
        }
    }

found:
    // If there are no empty cells, the board is solved
    if (row == SIZE && col == SIZE) {
        return true;
    }

    // Try all possible numbers for the empty cell
    for (int num = 1; num <= SIZE; num++) {
        // If the number is safe to place, place it and recursively solve the rest of the board
        if (is_safe(row, col, num)) {
            board[row][col] = num;
            if (solve()) {
                return true;
            }
            // If the recursive call fails, reset the cell to 0 and try the next number
            board[row][col] = 0;
        }
    }

    // If none of the numbers worked, the board is unsolvable
    return false;
}

int main() {
    // Read the Sudoku board from the input file
    FILE *fp = fopen("sudoku.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fscanf(fp, "%d ", &board[i][j]);
        }
    }
    fclose(fp);

    // Print the original Sudoku board
    printf("Original Sudoku board:\n");
    print_board();

    // Solve the Sudoku board
    if (solve()) {
        // Print the solved Sudoku board
        printf("\nSolved Sudoku board:\n");
        print_board();
    } else {
        printf("\nThe Sudoku board is unsolvable.\n");
    }

    return 0;
}