//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

#define UNASSIGNED 0
#define N 9

int grid[N][N];

int find_unassigned_location(int row, int col)
{
    for(row=0; row<N; row++)
    {
        for(col=0; col<N; col++)
        {
            if(grid[row][col] == UNASSIGNED)
            {
                return 1;
            }
        }
    }
    return 0;
}

int is_valid(int row, int col, int num)
{
    int row_start = row - row % 3;
    int col_start = col - col % 3;

    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(grid[row_start+i][col_start+j] == num)
            {
                return 0;
            }
        }
    }

    for(i=0; i<N; i++)
    {
        if(grid[row][i] == num || grid[i][col] == num)
        {
            return 0;
        }
    }

    return 1;
}

int solve_sudoku()
{
    int row,col;
    if(!find_unassigned_location(row, col))
    {
        return 1;
    }

    int num;
    for(num=1; num<=9; num++)
    {
        if(is_valid(row, col, num))
        {
            grid[row][col] = num;

            if(solve_sudoku())
            {
                return 1;
            }

            grid[row][col] = UNASSIGNED;
        }
    }

    return 0;
}

void print_sudoku()
{
    int i,j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i,j;

    printf("Enter the initial values of the Sudoku grid:\n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%d",&grid[i][j]);
        }
    }

    if(solve_sudoku())
    {
        printf("The solved Sudoku grid is: \n");
        print_sudoku();
    }
    else
    {
        printf("No solution was found for the given Sudoku grid\n");
    }

    return 0;
}