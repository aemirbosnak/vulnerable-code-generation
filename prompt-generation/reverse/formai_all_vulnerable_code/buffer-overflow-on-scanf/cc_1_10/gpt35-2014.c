//FormAI DATASET v1.0 Category: Sudoku solver ; Style: relaxed
#include<stdio.h>
#define N 9

// function to print the sudoku board
void printBoard(int board[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// function to check if a number is safe to place in a given row and column
int isSafe(int board[N][N], int row, int col, int num) {
    // check if num is present in the same row
    for(int i = 0; i < N; i++) {
        if(board[row][i] == num) {
            return 0;
        }
    }
    
    // check if num is present in the same column
    for(int i = 0; i < N; i++) {
        if(board[i][col] == num) {
            return 0;
        }
    }
    
    // check if num is present in the same 3x3 sub-grid
    int subRow = row - row%3;
    int subCol = col - col%3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[subRow+i][subCol+j] == num) {
                return 0;
            }
        }
    }
    
    // if num is not present in the same row, column or sub-grid, return 1 (true)
    return 1;
}

// function to solve the sudoku board
int solveSudoku(int board[N][N]) {
    int row, col;
    int emptySpace = 0;

    // check if the board is fully solved
    for(row = 0; row < N; row++) {
        for(col = 0; col < N; col++) {
            if(board[row][col] == 0) {
                emptySpace = 1;
                break;
            }
        }
        if(emptySpace) {
            break;
        }
    }
    if(!emptySpace) {
        return 1; // the board is fully solved
    }

    // loop through each number (1-9) to find a safe place to insert
    for(int num = 1; num <= 9; num++) {
        if(isSafe(board, row, col, num)) {
            board[row][col] = num;
            if(solveSudoku(board)) { // recursively solve the board
                return 1;
            }
            board[row][col] = 0; // undo the previous step if a solution is not found
        }
    }
    return 0; // backtrack (no solution found)
}

int main() {
    int board[N][N]; // create a 2D array for the sudoku board
    printf("Enter the sudoku board (0 for empty spaces):\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // solve the sudoku board and print the solution
    if(solveSudoku(board)) {
        printf("Solution:\n");
        printBoard(board);
    } else {
        printf("No solution found!\n");
    }

    return 0;
}