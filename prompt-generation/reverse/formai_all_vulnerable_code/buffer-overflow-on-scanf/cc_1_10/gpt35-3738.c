//FormAI DATASET v1.0 Category: Sudoku solver ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int grid[9][9];

void printGrid(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ", grid[i][j]);
            if(j==2 || j==5) printf("| ");
        }
        printf("\n");
        if(i==2 || i==5){
            for(int k=0;k<21;k++)
                printf("-");
            printf("\n");
        }
    }
}

int isValid(int row, int col, int num){
    //check row
    for(int i=0;i<9;i++){
        if(grid[row][i]==num) return 0;
    }
    //check column
    for(int i=0;i<9;i++){
        if(grid[i][col]==num) return 0;
    }
    //check box
    int boxRow = row - row%3;
    int boxCol = col - col%3;
    for(int i=boxRow;i<boxRow+3;i++){
        for(int j=boxCol;j<boxCol+3;j++){
            if(grid[i][j]==num) return 0;
        }
    }
    return 1;
}

int solve(int row, int col){
    if(row==9) return 1;
    int nextRow, nextCol;
    if(col==8){
        nextRow = row+1;
        nextCol = 0;
    }
    else{
        nextRow = row;
        nextCol = col+1;
    }
    if(grid[row][col]!=0) return solve(nextRow, nextCol);
    for(int i=1;i<=9;i++){
        if(isValid(row, col, i)){
            grid[row][col] = i;
            if(solve(nextRow, nextCol)){
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main(){
    printf("Enter the Sudoku grid(row-wise):\n");
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d", &grid[i][j]);
        }
    }
    printf("Sudoku grid:\n");
    printGrid();
    printf("Solved Sudoku grid:\n");
    if(solve(0, 0)){
        printGrid();
    }
    else{
        printf("Unable to solve the Sudoku grid.\n");
    }
    return 0;
}