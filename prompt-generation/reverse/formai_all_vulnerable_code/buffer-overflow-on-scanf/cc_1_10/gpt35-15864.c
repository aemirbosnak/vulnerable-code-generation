//FormAI DATASET v1.0 Category: Sudoku solver ; Style: light-weight
#include <stdio.h>

#define N 9  // Size of Sudoku grid
#define UNASSIGNED 0  // Represents an unassigned cell

// Function declarations
int solveSudoku(int grid[N][N]);
int findUnassigned(int grid[N][N], int *row, int *col);
int isSafe(int grid[N][N], int row, int col, int num);
void printSolution(int grid[N][N]);

// Main function
int main()
{
    int grid[N][N];
	
	// Input grid values
    printf("Enter 9x9 Sudoku grid (row-wise):\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    // Solve Sudoku
    if(solveSudoku(grid) == 1)
    {
        printf("\nSudoku grid solved:\n");
        printSolution(grid);
    }
    else
    {
        printf("\nInvalid Sudoku grid\n");
    }

    return 0;
}

// Recursive function to solve Sudoku
int solveSudoku(int grid[N][N])
{
    int row, col;

    // Check if every cell is assigned a number, return true
    if(!findUnassigned(grid, &row, &col))
    {
        return 1;
    }

    // Try different values in current unassigned cell
    for(int num=1; num<=9; num++)
    {
        if(isSafe(grid, row, col, num) == 1)
        {
            grid[row][col] = num;

            // Recursive call to solve the remaining grid
            if(solveSudoku(grid) == 1)
            {
                return 1;
            }

            // Backtrack
            grid[row][col] = UNASSIGNED;
        }
    }
    return 0;
}

// Find unassigned cell in the grid
int findUnassigned(int grid[N][N], int *row, int *col)
{
    for(*row=0; *row<N; (*row)++)
    {
        for(*col=0; *col<N; (*col)++)
        {
            if(grid[*row][*col] == UNASSIGNED)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Check if a number can be placed in the given cell
int isSafe(int grid[N][N], int row, int col, int num)
{
    // Check if num is already present in the same row
    for(int i=0; i<N; i++)
    {
        if(grid[row][i] == num)
        {
            return 0;
        }
    }

    // Check if num is already present in the same column
    for(int i=0; i<N; i++)
    {
        if(grid[i][col] == num)
        {
            return 0;
        }
    }

    // Check if num is already present in the same box
    int boxSize = 3;
    int boxStartRow = row - (row % boxSize);
    int boxStartCol = col - (col % boxSize);
    for(int i=0; i<boxSize; i++)
    {
        for(int j=0; j<boxSize; j++)
        {
            if(grid[boxStartRow+i][boxStartCol+j] == num)
            {
                return 0;
            }
        }
    }

    // If all checks pass, the number is safe to place
    return 1;
}

// Print solution grid
void printSolution(int grid[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}