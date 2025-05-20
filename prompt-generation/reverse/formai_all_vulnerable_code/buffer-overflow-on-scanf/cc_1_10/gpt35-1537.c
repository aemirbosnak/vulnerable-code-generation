//FormAI DATASET v1.0 Category: Sudoku solver ; Style: portable
#include<stdio.h>
#include<stdlib.h>

#define N 9

void printSudoku(int puzzle[N][N]){
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
            printf("%d ",puzzle[row][col]);
        }
        printf("\n");
    }
}

int isSafe(int puzzle[N][N],int row,int col,int num){
    //checking for numbers in the row
    for(int x=0;x<N;x++){
        if(puzzle[row][x]==num){
            return 0;
        }
    }
    //checking for numbers in the column
    for(int y=0;y<N;y++){
        if(puzzle[y][col]==num){
            return 0;
        }
    }
    //checking for numbers in the 3*3 sub-grid
    int sub_grid_row = row - row%3;
    int sub_grid_col = col - col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(puzzle[i+sub_grid_row][j+sub_grid_col]==num){
                return 0;
            }
        }
    }
    //if not in row,column or subgrid, the number is safe
    return 1;
}

int solveSudoku(int puzzle[N][N],int row,int col){
    //checking if all cells have been traversed
    if(row==N-1 && col==N){
        return 1;
    }
    //checking if we have reached the end of the column, then move to next row
    if(col==N){
        row++;
        col=0;
    }
    //if cell already has a number, move to next column
    if(puzzle[row][col]!=0){
        return solveSudoku(puzzle,row,col+1);
    }
    //checking for safe numbers to be placed
    for(int num=1;num<=N;num++){
        if(isSafe(puzzle,row,col,num)==1){
            puzzle[row][col]=num;
            if(solveSudoku(puzzle,row,col+1)==1){
                return 1;
            }
        }
        puzzle[row][col]=0;
    }
    return 0;
}

int main(){
    int puzzle[N][N];
    printf("Enter the Sudoku puzzle with blanks being denoted by 0:\n");
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
            scanf("%d",&puzzle[row][col]);
        }
    }
    printf("\nThe entered Sudoku puzzle is:\n");
    printSudoku(puzzle);
    if(solveSudoku(puzzle,0,0)==1){
        printf("\n\nThe solution to the Sudoku puzzle is:\n");
        printSudoku(puzzle);
    }
    else{
        printf("\n\nSolution does not exist for the given Sudoku puzzle!");
    }
    return 0;
}