//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 9

void create(int puzzle[N][N])
{
    int i,j;
    printf("\nEnter the elements of the Sudoku matrix:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d",&puzzle[i][j]);
        }
    }
}

void print(int puzzle[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ",puzzle[i][j]);
        }
        printf("\n");
    }
}

int isValid(int puzzle[N][N],int row,int col,int num)
{
    int i,j;
    for(i=0;i<N;i++)
    {
        if(puzzle[row][i]==num || puzzle[i][col]==num)
        {
            return 0;
        }
    }
    int startRow=row-row%N;
    int startCol=col-col%N;
    for(i=startRow;i<startRow+N;i++)
    {
        for(j=startCol;j<startCol+N;j++)
        {
            if(puzzle[i][j]==num)
            {
                return 0;
            }
        }
    }
    return 1;
}

void solve(int puzzle[N][N])
{
    int i,j;
    int row=0,col=0;
    int count=0;
    while(count<N*N)
    {
        if(col==N)
        {
            row++;
            col=0;
        }
        if(isValid(puzzle,row,col,1))
        {
            puzzle[row][col]=1;
            count++;
            col++;
        }
        else
        {
            col++;
        }
    }
}

int main()
{
    int puzzle[N][N];
    srand(time(0));
    create(puzzle);
    printf("\nThe unsolved Sudoku matrix is:\n");
    print(puzzle);
    solve(puzzle);
    printf("\nThe solved Sudoku matrix is:\n");
    print(puzzle);
    return 0;
}