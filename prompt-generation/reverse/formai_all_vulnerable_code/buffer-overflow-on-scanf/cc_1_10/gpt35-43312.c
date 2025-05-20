//FormAI DATASET v1.0 Category: Sudoku solver ; Style: surprised
#include<stdio.h>

int sudoku[9][9]; // representation of the sudoku grid 

// function to check if a value can be placed 
// at a given index
int isValid(int num, int row, int col) {
    int i, j;
    
    // check row values for the current column
    for(i = 0; i < 9; i++) {
        if(sudoku[row][i] == num) {
            return 0;
        }
    }
    
    // check column values for the current row
    for(i = 0; i < 9; i++) {
        if(sudoku[i][col] == num) {
            return 0;
        }
    }
    
    // check values in the current 3x3 box
    int boxRowStart = row - row % 3;
    int boxColStart = col - col % 3;
    
    for(i = boxRowStart; i < boxRowStart + 3; i++) {
        for(j = boxColStart; j < boxColStart + 3; j++) {
            if(sudoku[i][j] == num) {
                return 0;
            }
        }
    }
    
    // if none of the checks fail, return 1
    return 1;
}

// function to solve sudoku recursively
int solveSudoku(int row, int col) {
    int num;
    
    // check if we have reached the end of the grid
    if(row == 8 && col == 9) {
        return 1;
    }
    
    // check if we have reached the end of a row
    if(col == 9) {
        row++;
        col = 0;
    }
    
    // check if the current cell is already filled
    if(sudoku[row][col] > 0) {
        return solveSudoku(row, col+1);
    }
    
    // otherwise, try to fill the current cell with values 1 to 9
    for(num = 1; num <= 9; num++) {
        if(isValid(num, row, col)) {
            sudoku[row][col] = num;
            
            // recursive call to solve the remaining grid
            if(solveSudoku(row, col+1)) {
                return 1;
            }
        }
        sudoku[row][col] = 0;
    }
    
    // if all values fail, backtrack to the previous cell
    return 0;
}

int main() {
    int i, j;
    printf("Enter the sudoku grid (0 for empty cells):\n");
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
    
    // solve the sudoku using the recursive function
    if(solveSudoku(0, 0)) {
        printf("\nSolved Sudoku:\n");
        for(i = 0; i < 9; i++) {
            for(j = 0; j < 9; j++) {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("\nUnable to solve Sudoku.\n");
    }
    
    return 0;
}