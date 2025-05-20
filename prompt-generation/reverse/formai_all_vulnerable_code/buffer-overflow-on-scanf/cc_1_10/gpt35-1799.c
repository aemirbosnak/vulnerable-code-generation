//FormAI DATASET v1.0 Category: Sudoku solver ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

int grid[9][9];

// Function to print the grid
void printGrid()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the current number is valid in current position
int isValid(int row, int col, int num)
{
    // Check row and column
    for(int i=0;i<9;i++)
    {
        if(grid[row][i] == num || grid[i][col] == num)
            return 0;
    }

    // Check subgrid
    int subgridRow = (row / 3) * 3;
    int subgridCol = (col / 3) * 3;
    for(int i=subgridRow;i<subgridRow+3;i++)
    {
        for(int j=subgridCol;j<subgridCol+3;j++)
        {
            if(grid[i][j] == num)
                return 0;
        }
    }

    return 1;
}

// Function to solve the Sudoku using backtracking
int solveSudoku()
{
    for(int row=0;row<9;row++)
    {
        for(int col=0;col<9;col++)
        {
            // If the cell is empty, try out all numbers from 1 to 9
            if(grid[row][col] == 0)
            {
                for(int num=1;num<=9;num++)
                {
                    if(isValid(row, col, num))
                    {
                        grid[row][col] = num;

                        if(solveSudoku())
                            return 1;

                        grid[row][col] = 0; // Backtrack
                    }
                }
                return 0; // No valid number found
            }
        }
    }
    return 1; // Solved
}

int main()
{
    // Initialization of Sudoku grid
    printf("Enter the Sudoku grid(0 for empty cell):\n");
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("The Sudoku grid before solving is:\n");
    printGrid();

    if(solveSudoku())
    {
        printf("The Sudoku grid after solving is:\n");
        printGrid();
    }
    else
    {
        printf("Invalid Sudoku!\n");
    }

    return 0;
}