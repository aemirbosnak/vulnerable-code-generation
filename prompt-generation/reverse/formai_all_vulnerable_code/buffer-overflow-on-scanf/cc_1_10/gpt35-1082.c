//FormAI DATASET v1.0 Category: Sudoku solver ; Style: mathematical
#include <stdio.h>

int grid[9][9];

void inputGrid(){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("Enter grid[%d][%d]: ", i, j);
            scanf("%d", &grid[i][j]);
        }
    }
}

int isValid(int row, int col, int num){
    int i,j;

    // Check row
    for(j=0;j<9;j++){
        if(grid[row][j] == num)
            return 0;
    }

    // Check column
    for(i=0;i<9;i++){
        if(grid[i][col] == num)
            return 0;
    }

    // Check subgrid
    int startRow = row - row%3;
    int startCol = col - col%3;
    for(i=startRow;i<startRow+3;i++){
        for(j=startCol;j<startCol+3;j++){
            if(grid[i][j] == num)
                return 0;
        }
    }

    return 1;
}

int solveSudoku(){
    int i,j,num;

    // Find empty cell
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(grid[i][j] == 0){
                // Try all numbers
                for(num=1;num<=9;num++){
                    if(isValid(i,j,num)){
                        // Assign number
                        grid[i][j] = num;

                        // Recurse
                        if(solveSudoku())
                            return 1;

                        // Undo
                        grid[i][j] = 0;
                    }
                }

                return 0;
            }
        }
    }

    // Solved
    return 1;
}

void printGrid(){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main(){
    inputGrid();

    if(solveSudoku())
        printGrid();
    else
        printf("No solution exists.");

    return 0;
}