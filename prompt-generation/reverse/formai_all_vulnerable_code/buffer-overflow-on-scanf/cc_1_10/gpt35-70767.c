//FormAI DATASET v1.0 Category: Sudoku solver ; Style: inquisitive
#include <stdio.h>
#include <stdbool.h>

#define N 9 //size of the Sudoku grid

//function to check if the current number is valid for the given cell
bool isValid(int puzzle[N][N], int row, int col, int num) {
    //check row
    for(int i = 0; i < N; i++) {
        if(puzzle[row][i] == num)
            return false;
    }
    //check column
    for(int i = 0; i < N; i++) {
        if(puzzle[i][col] == num)
            return false;
    }
    //check sub-grid
    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;
    for(int i = start_row; i < start_row+3; i++) {
        for(int j = start_col; j < start_col+3; j++) {
            if(puzzle[i][j] == num)
                return false;
        }
    }
    return true;
}

//function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int puzzle[N][N]) {
    int row, col;
    //check if there is any empty cell
    bool emptyCell = false;
    for(row = 0; row < N; row++) {
        for(col = 0; col < N; col++) {
            if(puzzle[row][col] == 0) {
                emptyCell = true;
                break;
            }
        }
        if(emptyCell)
            break;
    }
    //if all cells are filled, return true
    if(!emptyCell)
        return true;
    //else try to fill the cells with valid numbers
    for(int i = 1; i <= 9; i++) {
        if(isValid(puzzle, row, col, i)) {
            puzzle[row][col] = i;
            //recursively solve the remaining puzzle
            if(solveSudoku(puzzle))
                return true;
            //if the current number is not valid, backtrack and try with a different number
            puzzle[row][col] = 0;
        }
    }
    //if no number is valid for the current cell, return false
    return false;
}

//function to print the solved Sudoku puzzle
void printSudoku(int puzzle[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int puzzle[N][N];
    printf("Enter the Sudoku puzzle (use 0 for empty cells):\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &puzzle[i][j]);
        }
    }
    if(solveSudoku(puzzle)) {
        printf("Solved Sudoku puzzle:\n");
        printSudoku(puzzle);
    }
    else {
        printf("No solution exists for the given puzzle.\n");
    }
    return 0;
}