//FormAI DATASET v1.0 Category: Sudoku solver ; Style: brave
#include <stdio.h>
#define N 9

int grid[N][N];

void input_sudoku(void)
{
    printf("Enter the unsolved Sudoku (row-wise):\n");
    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            scanf("%d",&grid[row][col]);
        }
    }
}

void display_sudoku(void)
{
    printf("\nThe entered Sudoku grid is:\n");
    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            printf("%2d ",grid[row][col]);
        }
        printf("\n");
    }
}

int is_valid_number(int row, int col, int num)
{
    for(int i=0;i<N;i++)
    {
        if(grid[row][i]==num || grid[i][col]==num || grid[(row/3)*3+i/3][(col/3)*3+i%3]==num)
        {
            return 0;
        }
    }
    return 1;
}

int solve_sudoku(int row, int col)
{
    if(row==N-1 && col==N)
    {
        return 1;
    }
    if(col==N)
    {
        row++;
        col=0;
    }
    if(grid[row][col]>0)
    {
        return solve_sudoku(row,col+1);
    }
    for(int i=1;i<=N;i++)
    {
        if(is_valid_number(row,col,i))
        {
            grid[row][col]=i;
            if(solve_sudoku(row,col+1))
            {
                return 1;
            }
        }
        grid[row][col]=0;
    }
    return 0;
}

int main()
{
    input_sudoku();
    display_sudoku();

    if(solve_sudoku(0,0))
    {
        printf("\nThe solved Sudoku is:\n");
        for(int row=0;row<N;row++)
        {
            for(int col=0;col<N;col++)
            {
                printf("%2d ",grid[row][col]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nUnable to solve Sudoku\n");
    }

    return 0;
}