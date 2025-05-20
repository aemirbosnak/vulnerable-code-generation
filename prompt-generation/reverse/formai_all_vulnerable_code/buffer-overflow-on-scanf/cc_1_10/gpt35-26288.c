//FormAI DATASET v1.0 Category: Sudoku solver ; Style: random
#include <stdio.h>
#include <stdlib.h>

// define sudoku grid 9x9
#define N 9

// function prototype for solving sudoku
int solve_sudoku(int grid[N][N], int row, int col);

// function prototype for checking if a number can be placed at a specific cell
int check_cell(int grid[N][N], int row, int col, int num);

// function prototype for printing the solved sudoku grid
void print_grid(int grid[N][N]);

// our main function
int main()
{
    int grid[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0} };
    int i, j;

    // take input from user
    printf("Enter the unsolved Sudoku grid (Use 0 for blank cells):\n");
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    // solving the sudoku grid
    if(solve_sudoku(grid, 0, 0))
    {
        // printing the solved grid
        printf("\n\nSolved Sudoku grid:\n");
        print_grid(grid);
    }
    else
    {
        printf("No solution exists for the given Sudoku grid!\n");
    }

    return 0;
}

// function to solve the sudoku grid recursively
int solve_sudoku(int grid[N][N], int row, int col)
{
    int num;

    // if we have reached end of the grid, the sudoku has been solved
    if(row == N-1 && col == N)
    {
        return 1;
    }

    // if end of row is reached, move to next row
    if(col == N)
    {
        row++;
        col = 0;
    }

    // if cell is not empty, continue to next cell
    if(grid[row][col] != 0)
    {
        return solve_sudoku(grid, row, col+1);
    }

    // check every number between 1 to 9 to see if it can be placed at the current cell
    for(num=1; num<=9; num++)
    {
        if(check_cell(grid, row, col, num))
        {
            grid[row][col] = num;

            if(solve_sudoku(grid, row, col+1))
            {
                return 1;
            }
        }

        grid[row][col] = 0;
    }

    // if no number can be placed, backtrack to previous cell and try again with a different number
    return 0;
}

// function to check if a number can be placed at a specific cell
int check_cell(int grid[N][N], int row, int col, int num)
{
    int i, j;

    // check row and column for the presence of same number
    for(i=0; i<N; i++)
    {
        if(grid[row][i] == num || grid[i][col] == num)
        {
            return 0;
        }
    }

    // check 3x3 sub grid for the presence of same number
    int row_start = row - row % 3;
    int col_start = col - col % 3;

    for(i=row_start; i<row_start+3; i++)
    {
        for(j=col_start; j<col_start+3; j++)
        {
            if(grid[i][j] == num)
            {
                return 0;
            }
        }
    }

    // number can be placed at the current cell
    return 1;
}

// function to print the solved grid
void print_grid(int grid[N][N])
{
    int i, j;

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}