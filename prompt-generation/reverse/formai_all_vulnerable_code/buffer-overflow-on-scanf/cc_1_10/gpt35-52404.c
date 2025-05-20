//FormAI DATASET v1.0 Category: Sudoku solver ; Style: future-proof
#include <stdio.h>

#define SIZE 9

int board[SIZE][SIZE];

// Function to check if the number n is available in row, column, and box
int is_available(int row, int col, int num) {
    // Check row
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) return 0;
    }

    // Check column
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) return 0;
    }
    
    // Check box
    int box_row = row - (row % 3);
    int box_col = col - (col % 3);
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) return 0;
        }
    }

    return 1;
}

// Recursive function to solve the sudoku board
int sudoku_solver() {
    int row, col, result = 0;

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_available(row, col, num)) {
                        board[row][col] = num;

                        // Recursion
                        if (sudoku_solver()) {
                            return 1;
                        }
                        else {
                            board[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }

    return 1;
}

// Function to print the board
void print_board() {
    for (int i = 0; i < SIZE; i++) {
        if (i % 3 == 0 && i != 0) printf("-------------------------\n");
        for (int j = 0; j < SIZE; j++) {
            if (j % 3 == 0 && j != 0) printf("| ");
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the Sudoku board with 0s indicating empty cells:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    if (sudoku_solver()) {
        printf("\nSudoku board solution:\n");
        print_board();
    }
    else {
        printf("\nInvalid Sudoku board!\n");
    }

    return 0;
}