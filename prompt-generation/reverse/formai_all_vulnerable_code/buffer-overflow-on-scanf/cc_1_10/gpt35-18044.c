//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include<stdio.h>  //include standard I/O library

//Function to check if the digit is safe to be placed at the given position
int isSafe(int board[9][9], int row, int col, int digit) {
    //Check if the digit exists in current row or column
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == digit || board[i][col] == digit) {
            return 0;
        }
    }
    //Check if the digit exists in current 3x3 subgrid
    int subgrid_row_start = (row / 3) * 3;
    int subgrid_col_start = (col / 3) * 3;
    for (int i = subgrid_row_start; i < subgrid_row_start + 3; i++) {
        for (int j = subgrid_col_start; j < subgrid_col_start + 3; j++) {
            if (board[i][j] == digit) {
                return 0;
            }
        }
    }
    return 1;
}

//Function to solve the Sudoku using backtracking
int solveSudoku(int board[9][9]) {
    int row, col;
    //Find first empty cell in the board
    int flag = 1;
    for (row = 0; row < 9 && flag; row++) {
        for (col = 0; col < 9 && flag; col++) {
            if (board[row][col] == 0) {
                flag = 0;
            }
        }
    }
    //If the whole board is filled, then it is solved
    if (row == 9 && col == 9) {
        return 1;
    }
    //Try out all possible digits (1-9) in the current empty cell
    for (int digit = 1; digit <= 9; digit++) {
        if (isSafe(board, row, col, digit)) {
            board[row][col] = digit;
            //Try to solve the remaining board recursively
            if (solveSudoku(board)) {
                return 1;
            }
            //If the remaining board can't be solved with this digit, reset the cell to 0
            board[row][col] = 0;
        }
    }
    //If no digits could solve the remaining board, backtrack
    return 0;
}

//Main program
int main() {
    int board[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0}}; 
    printf("Enter the unsolved Sudoku board (0 for empty cells):\n");
    //Read input from user
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    //Solve the Sudoku board
    if (solveSudoku(board)) {
        printf("Solved Sudoku board:\n");
        //Print solved board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Sorry, the given Sudoku board can't be solved!\n");
    }
    return 0; //Exit program
}