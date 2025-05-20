//FormAI DATASET v1.0 Category: Sudoku solver ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#define S 9

//Function to check if the given digit is safe to put at given position
int isSafe(int grid[S][S],int row,int col,int num)
{
    //check if the same digit is already present in the same row
    for(int i=0;i<S;i++)
    {
        if(grid[row][i]==num)
            return 0;
    }

    //check if the same digit is already present in the same column
    for(int i=0;i<S;i++)
    {
        if(grid[i][col]==num)
            return 0;
    }

    //check if the same digit is already present in the same 3x3 box
    int temp_row=row-row%3,temp_col=col-col%3;
    for(int i=temp_row;i<temp_row+3;i++)
    {
        for(int j=temp_col;j<temp_col+3;j++)
        {
            if(grid[i][j]==num)
                return 0;
        }
    }

    //if the digit is safe to put, return 1
    return 1;
}

//Function to print the Sudoku grid
void printGrid(int grid[S][S])
{
    for(int i=0;i<S;i++)
    {
        for(int j=0;j<S;j++)
            printf("%d ",grid[i][j]);
        printf("\n");
    }
}

//Function to solve the Sudoku puzzle using backtracking technique
int solveSudoku(int grid[S][S],int row,int col)
{
    //if the column exceeds 8, move to next row
    if(col>=S)
    {
        row++;
        col=0;
    }

    //if the row exceeds 8, the Sudoku is solved
    if(row>=S)
        return 1;

    //if the cell already has a given digit, move to the next cell
    if(grid[row][col]!=0)
        return solveSudoku(grid,row,col+1);

    //try putting every possible digit(from 1 to 9) in the cell
    for(int i=1;i<=9;i++)
    {
        if(isSafe(grid,row,col,i))
        {
            //if the digit is safe to put, put it in the cell
            grid[row][col]=i;

            //solve the remaining Sudoku recursively
            if(solveSudoku(grid,row,col+1))
                return 1;

            //if the remaining Sudoku can't be solved, backtrack
            grid[row][col]=0;
        }
    }

    //if no digit can be put in the cell, return 0
    return 0;
}

int main()
{
    int grid[S][S]={0};
    printf("Enter the Sudoku puzzle:\n");
    for(int i=0;i<S;i++)
    {
        for(int j=0;j<S;j++)
            scanf("%d",&grid[i][j]);
    }

    printf("\nSolving the Sudoku puzzle...\n\n");

    //call the solveSudoku function to solve the Sudoku puzzle
    if(solveSudoku(grid,0,0)==1)
    {
        printf("Sudoku solution:\n");
        printGrid(grid);
    }
    else
        printf("Given Sudoku cannot be solved!\n");

    return 0;
}