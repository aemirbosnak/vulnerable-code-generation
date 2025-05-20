//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

int checkValidity(int board[][9], int row, int col, int num){
    //checking for row and column validity of num
    for(int i=0;i<9;i++)
        if(board[row][i]==num || board[i][col]==num)
            return 0;
    //checking for validity in the 3x3 box
    int startRow = row-(row%3), startCol = col-(col%3);
    for(int i=startRow;i<startRow+3;i++)
        for(int j=startCol;j<startCol+3;j++)
            if(board[i][j]==num)
                return 0;
    return 1;
}

void printBoard(int board[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            printf("%d ",board[i][j]);
        printf("\n");
    }
}

int findEmptyLocation(int board[][9],int *row,int *col){
    for(*row=0;*row<9;(*row)++)
        for(*col=0;*col<9;(*col)++)
            if(board[*row][*col]==0)
                return 1;
    return 0;
}

int solveSudoku(int board[][9]){
    int row,col;
    if(!findEmptyLocation(board,&row,&col))
        return 1;
    for(int i=1;i<=9;i++){
        if(checkValidity(board,row,col,i)){
            board[row][col]=i;
            if(solveSudoku(board))
                return 1;
            board[row][col]=0;
        }
    }
    return 0;
}

int main(){
    int board[9][9];
    printf("Enter the sudoku puzzle (one row per line, use 0 for empty cells):\n");
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            scanf("%d",&board[i][j]);
    if(solveSudoku(board))
        printBoard(board);
    else
        printf("No solution exists!");
    return 0;
}