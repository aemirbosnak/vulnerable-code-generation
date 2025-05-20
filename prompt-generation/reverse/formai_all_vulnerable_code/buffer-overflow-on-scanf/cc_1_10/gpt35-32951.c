//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
/* 
  C Sudoku Solver
  Decentralized style program

  By: [Your Name Here]

*/

#include <stdio.h>

#define BOARD_SIZE 9

int board[BOARD_SIZE][BOARD_SIZE];

// Function to print the board
void print_board() {
    printf("-----------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("| %d ", board[i][j]);
        }
        printf("|\n");
        printf("-----------------------\n");
    }
}

// Function to check if a number is valid in a given row
int check_row(int row, int num) {
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[row][j] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a number is valid in a given column
int check_col(int col, int num) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a number is valid in a given 3x3 subgrid
int check_subgrid(int row, int col, int num) {
    int sub_row = (row / 3) * 3;
    int sub_col = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[sub_row+i][sub_col+j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if a number is valid in a given position
int is_valid(int row, int col, int num) {
    return check_row(row, num) && check_col(col, num) && check_subgrid(row, col, num);
}

// Function to recursively solve the board
int solve(int row, int col) {
    if (row == BOARD_SIZE) {
        return 1; // Board is solved
    }
    if (board[row][col] > 0) { // If the cell is already filled
        if (col == BOARD_SIZE-1) {
            if (solve(row+1, 0)) {
                return 1;
            }
        } else {
            if (solve(row, col+1)) {
                return 1;
            }
        }
        return 0; // If the next cell couldn't be solved, go back and try a different number
    }
    for (int num = 1; num <= BOARD_SIZE; num++) {
        if (is_valid(row, col, num)) {
            board[row][col] = num;
            if (col == BOARD_SIZE-1) {
                if (solve(row+1, 0)) {
                    return 1;
                }
            } else {
                if (solve(row, col+1)) {
                    return 1;
                }
            }
            board[row][col] = 0;
        }
    }
    return 0; // If no valid number can be placed in the current cell, go back and try a different number
}

int main() {
    printf("Enter the numbers for the Sudoku puzzle (0 for empty cells):\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    if (solve(0, 0)) {
        printf("Sudoku puzzle solved successfully:\n");
        print_board();
    } else {
        printf("No solution found!\n");
    }
    return 0;
}