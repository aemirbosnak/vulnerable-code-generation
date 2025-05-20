//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

// Function to check if a number is valid in a given row and column
int is_valid(int board[MAX_SIZE][MAX_SIZE], int row, int col, int num) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return 0;
        }
    }
    int sub_row = row - row % 3;
    int sub_col = col - col % 3;
    for (int i = sub_row; i < sub_row + 3; i++) {
        for (int j = sub_col; j < sub_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the Sudoku puzzle
int solve_sudoku(int board[MAX_SIZE][MAX_SIZE]) {
    int row = 0, col = 0;
    while (row < MAX_SIZE) {
        while (col < MAX_SIZE) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= MAX_SIZE; num++) {
                    if (is_valid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solve_sudoku(board)) {
                            return 1;
                        } else {
                            board[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
            col++;
        }
        row++;
        col = 0;
    }
    return 1;
}

// Function to print the Sudoku board
void print_board(int board[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int board[MAX_SIZE][MAX_SIZE];
    int row, col;
    printf("Enter the Sudoku puzzle:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    if (solve_sudoku(board)) {
        printf("Solution:\n");
        print_board(board);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}