//FormAI DATASET v1.0 Category: Sudoku solver ; Style: active
#include<stdio.h>

int board[9][9]; // board for Sudoku puzzle

// function to check if a number can be placed in a cell
int isPossible(int row,int col,int num)
{
    // check row
    for(int i=0;i<9;i++)
        if(board[row][i]==num)
            return 0;

    // check column
    for(int i=0;i<9;i++)
        if(board[i][col]==num)
            return 0;

    // check 3x3 square
    int startRow=(row/3)*3;
    int startCol=(col/3)*3;
    for(int i=startRow;i<startRow+3;i++)
        for(int j=startCol;j<startCol+3;j++)
            if(board[i][j]==num)
                return 0;

    return 1;
}

// function to solve the puzzle
int solve(int row,int col)
{
    if(row==9)
        return 1;

    if(col==9)
        return solve(row+1,0);

    if(board[row][col]!=0)
        return solve(row,col+1);

    for(int i=1;i<=9;i++)
    {
        if(isPossible(row,col,i))
        {
            board[row][col]=i;

            if(solve(row,col+1))
                return 1;

            board[row][col]=0;
        }
    }

    return 0;
}

// function to display the solved puzzle
void display()
{
    printf("-----------------------\n");
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            printf(" %d ",board[i][j]);
        printf("\n");

        if(i%3==2)
            printf("-----------------------\n");
    }
}

int main()
{
    printf("Enter the puzzle (use 0 for empty cells):\n");
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            scanf("%d",&board[i][j]);

    if(solve(0,0))
    {
        printf("Solved Puzzle:\n");
        display();
    }
    else
        printf("Invalid Puzzle\n");

    return 0;
}