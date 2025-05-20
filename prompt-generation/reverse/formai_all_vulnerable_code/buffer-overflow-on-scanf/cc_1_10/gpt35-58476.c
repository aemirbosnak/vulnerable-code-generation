//FormAI DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>

int board[9][9];

// function to check if a number can be placed in a particular cell
int isValid(int row, int col, int num) {
    // check if the number is already present in the row or column
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return 0;
    }
    
    // check if the number is already present in the 3x3 sub-grid
    int subRow = (row / 3) * 3;
    int subCol = (col / 3) * 3;
    for (int i = subRow; i < subRow + 3; i++) {
        for (int j = subCol; j < subCol + 3; j++) {
            if (board[i][j] == num)
                return 0;
        }
    }
    
    // if number is not present in row, column, or sub-grid, it can be placed in cell
    return 1;
}

// function to solve the Sudoku board using backtracking
int solve(int row, int col) {
    // if we have reached the last cell, return 1 to indicate successful completion
    if (row == 9)
        return 1;
    
    // if we have reached the end of a row, move to the beginning of next row
    if (col == 9)
        return solve(row + 1, 0);
    
    // if the cell is already filled, move to the next cell in the same row
    if (board[row][col] != 0)
        return solve(row, col + 1);
    
    // iterate through all possible values for the current cell
    for (int i = 1; i <= 9; i++) {
        if (isValid(row, col, i)) {
            board[row][col] = i;
            if (solve(row, col + 1))
                return 1;
            board[row][col] = 0; // backtrack
        }
    }
    
    // if no valid value can be placed in the cell, return 0 to indicate failure
    return 0;
}

int main() {
    // read input from stdin
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    
    // solve the Sudoku board
    if (solve(0, 0)) {
        // print the solution
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("No solution found.");
    }
    
    return 0;
}