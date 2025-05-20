//FormAI DATASET v1.0 Category: Sudoku solver ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#define UNASSIGNED 0
#define N 9

// Function to print the Sudoku Grid
void printSudoku(int grid[][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check whether it is safe to place a number in that respective cell or not
int isSafe(int grid[][N], int row, int col, int num)
{
    // Checking if the number is present in same row or column
    for(int i=0;i<N;i++)
        if(grid[row][i]==num || grid[i][col]==num)
            return 0;
    //Checking if the number is present in the respective 3x3 grid
    int rowStart=row-row%3;
    int colStart=col-col%3;
    for(int i=rowStart;i<rowStart+3;i++)
    {
        for(int j=colStart;j<colStart+3;j++)
        {
            if(grid[i][j]==num)
                return 0;
        }
    }
    //If the number is not present in any row,col or 3x3 grid then it's safe to place
    return 1;
}

//Solving the Sudoku   
int solveSudoku(int grid[][N], int row, int col)
{
    if(row==N-1 && col==N)
    {
        return 1; //Sudoku is solved
    }
    if(col==N) //Moving to next row
    {
        row++;
        col=0;
    }
    if(grid[row][col]>0) // If the cell is already filled with number then move(Back-Tracking) to next cell
    {
        return solveSudoku(grid,row,col+1);
    }
    for(int num=1; num<=N; num++)//Trying to place the number
    {
        if(isSafe(grid,row,col,num))//Checking if it's safe to place this number
        {
            grid[row][col]=num;//Placing the number in the cell
            if(solveSudoku(grid,row,col+1))// Recursively solving the sudoku until it's solved successfully
                return 1;
        }
        grid[row][col]=UNASSIGNED;// If it's not successful then backtrack and remove the number from the cell
    }
    return 0;
}

// Main function
int main()
{
    int grid[N][N];
    printf("Enter the Sudoku Grid (Enter 0 for empty cells): \n"); //Taking the input Sudoku Grid
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&grid[i][j]);
        }
    }
    printf("\nGiven Sudoku: \n");
    printSudoku(grid); //Printing the Sudoku before solving
    if(solveSudoku(grid,0,0)) //If the Sudoku is solved successfully, Then print the solved Sudoku
    {
        printf("\nSolved Sudoku: \n");
        printSudoku(grid);
    }
    else //If sudoku is not solvable, print error message
        printf("\nUnable to solve the given Sudoku.\n");
    return 0;
}