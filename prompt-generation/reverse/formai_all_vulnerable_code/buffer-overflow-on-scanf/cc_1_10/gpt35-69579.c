//FormAI DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include <stdio.h>

#define SIZE 9

int board[SIZE][SIZE];

/**
 * This function checks if the row, column or 3x3 grid 
 * contains the given number
 **/
int isSafe(int row, int col, int num) {
    for(int i=0; i<SIZE; i++) {
        if(board[row][i] == num) return 0;
        if(board[i][col] == num) return 0;
        if(board[row-row%3+i/3][col-col%3+i%3] == num) return 0; 
    }
    return 1;
}

/**
 * This function solves the Sudoku puzzle using recursion
 **/
int solveSudoku(int row, int col) {
    if(row == SIZE-1 && col == SIZE) {
        return 1;
    }
    if(col == SIZE) {
        row++;
        col = 0;
    }
    if(board[row][col] > 0) {
        return solveSudoku(row, col+1);
    }
    for(int num=1; num<=SIZE; num++) {
        if(isSafe(row, col, num)) {
            board[row][col] = num;
            if(solveSudoku(row, col+1)) {
                return 1;
            }
        }
        board[row][col] = 0;
    }
    return 0;
}

int main() {
    printf("Enter the Sudoku puzzle (use 0 for blank cells):\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    if (solveSudoku(0, 0)) {
        printf("\nThe solved Sudoku is:\n");
        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<SIZE; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists!\n");
    }

    return 0;
}