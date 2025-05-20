//FormAI DATASET v1.0 Category: Sudoku solver ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int board[9][9] = {0}; // initialize board as 0

// function to print the board
void print_board() {
    printf("\n-------------------------\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) printf("|   ");
            else printf("| %d ", board[i][j]);
        }
        printf("|\n");
        printf("-------------------------\n");
    }
}

// function to check if the cell is safe to place the number
int is_safe(int row, int col, int num) {
    // check row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) return 0;
    }

    // check column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) return 0;
    }

    // check the box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) return 0;
        }
    }

    // if all tests pass, return true
    return 1;
}

// function to solve the Sudoku puzzle using backtracking
int solve(int row, int col) {
    // if we reached the end of the board, the puzzle is solved
    if (row == 9 && col == 0) {
        return 1;
    }

    // if we reached the end of the row, move to the next row
    if (col == 9) {
        row++;
        col = 0;
    }

    // if the cell is already filled, move to the next cell
    if (board[row][col] != 0) {
        return solve(row, col + 1);
    }

    // for each number from 1 to 9, check if it's safe to place it in the cell
    for (int num = 1; num <= 9; num++) {
        if (is_safe(row, col, num)) {
            board[row][col] = num;
            if (solve(row, col + 1)) return 1; // move to the next cell
            board[row][col] = 0; // backtrack
        }
    }

    // if no number works, backtrack to the previous cell
    return 0;
}

int main() {
    // input the Sudoku puzzle
    printf("Enter the Sudoku puzzle:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // solve the Sudoku puzzle
    if (solve(0, 0)) {
        printf("\nThe solution to the Sudoku puzzle is:\n");
        print_board();
    } else {
        printf("\nThe Sudoku puzzle has no solution.\n");
    }

    return 0;
}