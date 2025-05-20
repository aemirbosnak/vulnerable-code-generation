//FormAI DATASET v1.0 Category: Sudoku solver ; Style: creative
#include<stdio.h>
#include<stdlib.h>

#define GRID_SIZE 9

int grid[GRID_SIZE][GRID_SIZE];

// function to print the grid
void printGrid() {
    printf("-------------------------------\n");
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            printf("| %d ",grid[i][j]);
        }
        printf("|\n");
        printf("-------------------------------\n");
    }
}

// check if the given number already exists in the row
int checkRow(int row, int num) {
    for(int i=0; i<GRID_SIZE; i++) {
        if(grid[row][i] == num) {
            return 1;
        }
    }
    return 0;
}

// check if the given number already exists in the column
int checkCol(int col, int num) {
    for(int i=0; i<GRID_SIZE; i++) {
        if(grid[i][col] == num) {
            return 1;
        }
    }
    return 0;
}

// check if the given number already exists in the box
int checkBox(int x, int y, int num) {
    int rowStart = x - x%3;
    int colStart = y - y%3;

    for(int i=rowStart; i<rowStart+3; i++) {
        for(int j=colStart; j<colStart+3; j++) {
            if(grid[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// check if it's safe to place the number in the given cell
int isSafe(int x, int y, int num) {
    if(checkRow(x,num) || checkCol(y,num) || checkBox(x,y,num)) {
        return 0;
    }
    return 1;
}

// function to solve the Sudoku
int solveSudoku(int x, int y) {
    if(x == GRID_SIZE-1 && y == GRID_SIZE) {
        return 1;
    }

    if(y == GRID_SIZE) {
        x++;
        y=0;
    }

    if(grid[x][y] != 0) {
        return solveSudoku(x,y+1);
    }

    for(int i=1; i<=GRID_SIZE; i++) {
        if(isSafe(x,y,i)==1) {
            grid[x][y] = i;

            if(solveSudoku(x,y+1)==1) {
                return 1;
            }
        }
        grid[x][y] = 0;
    }
    return 0;
}

int main() {
    printf("Enter the Sudoku grid (0 for unknown cells):\n");
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            scanf("%d",&grid[i][j]);
        }
    }

    printf("The entered Sudoku grid is:\n");
    printGrid();

    if(solveSudoku(0,0) == 1) {
        printf("The solution to the Sudoku grid is:\n");
        printGrid();
    }
    else {
        printf("The given Sudoku grid does not have a solution.\n");
    }

    return 0;
}