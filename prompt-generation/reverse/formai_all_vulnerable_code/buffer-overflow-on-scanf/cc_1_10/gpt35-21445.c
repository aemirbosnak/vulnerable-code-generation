//FormAI DATASET v1.0 Category: Sudoku solver ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>

int grid[9][9];

bool usedInRow(int row, int num) {
    for(int col=0; col<9; col++) {
        if(grid[row][col]==num) return true;
    }
    return false;
}

bool usedInCol(int col, int num) {
    for(int row=0; row<9; row++) {
        if(grid[row][col]==num) return true;
    }
    return false;
}

bool usedInBox(int rowStart, int colStart, int num) {
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            if(grid[row+rowStart][col+colStart]==num) return true;
        }
    }
    return false;
}

bool isSafe(int row, int col, int num) {
    return !usedInRow(row,num) && !usedInCol(col,num) && !usedInBox(row-row%3,col-col%3,num);
}

bool findUnassigned(int* row, int* col) {
    for(*row=0; *row<9; (*row)++) {
        for(*col=0; *col<9; (*col)++) {
            if(grid[*row][*col]==0) return true;
        }
    }
    return false;
}

bool solveSudoku() {
    int row, col;
    if(!findUnassigned(&row,&col)) return true;
    for(int num=1; num<=9; num++) {
        if(isSafe(row,col,num)) {
            grid[row][col]=num;
            if(solveSudoku()) return true;
            grid[row][col]=0;
        }
    }
    return false;
}

void printGrid() {
    for(int row=0; row<9; row++) {
        for(int col=0; col<9; col++) {
            printf("%d ",grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the Sudoku grid (row-wise):\n");
    for(int row=0; row<9; row++) {
        for(int col=0; col<9; col++) {
            scanf("%d",&grid[row][col]);
        }
    }
    printf("The given Sudoku grid is:\n");
    printGrid();
    if(solveSudoku()) {
        printf("The solved Sudoku grid is:\n");
        printGrid();
    } else {
        printf("No solution exists for the given Sudoku grid!\n");
    }
    return 0;
}