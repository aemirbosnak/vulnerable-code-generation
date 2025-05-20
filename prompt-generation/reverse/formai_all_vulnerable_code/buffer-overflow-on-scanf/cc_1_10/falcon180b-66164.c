//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: genious
#include<stdio.h>
#include<stdlib.h>

void printSudoku(int board[9][9])
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

void solveSudoku(int board[9][9],int i,int j)
{
    int n;
    for(n=1;n<=9;n++)
    {
        if(board[i][j]==n&&isSafe(board,i,j,n))
        {
            board[i][j]=n;
            if(j==8)
            {
                j=0;
                i++;
            }
            else
            {
                j++;
            }
            solveSudoku(board,i,j);
        }
    }
    board[i][j]='0';
}

int isSafe(int board[9][9],int i,int j,int n)
{
    int count=0;
    int k;
    for(k=0;k<9;k++)
    {
        if(board[i][k]==n)
        {
            count++;
        }
        if(board[k][j]==n)
        {
            count++;
        }
        if(board[3*(i/3)+k/3][3*(j/3)+k/3]==n)
        {
            count++;
        }
    }
    if(count>1)
    {
        return 0;
    }
    return 1;
}

void main()
{
    int board[9][9];
    int i,j;
    int n;
    int flag=0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("Enter element %d %d : ",i+1,j+1);
            scanf("%d",&board[i][j]);
            if(board[i][j]==0)
            {
                flag=1;
            }
        }
    }
    if(flag==0)
    {
        printf("The Sudoku is already solved.\n");
    }
    else
    {
        solveSudoku(board,0,0);
        printf("The Sudoku is solved.\n");
        printSudoku(board);
    }
}