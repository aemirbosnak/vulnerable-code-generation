//FormAI DATASET v1.0 Category: Sudoku solver ; Style: systematic
#include<stdio.h>

int grid[9][9]; //the Sudoku grid

//Function to check if the Sudoku is filled completely
int isComplete()
{
    int i, j;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(grid[i][j] == 0) //if there's an empty cell
                return 0; //return 0, Sudoku is not complete
        }
    }
    return 1; //Sudoku complete
}

//Function to check if the given number is valid in the given cell
int isValid(int row, int col, int num)
{
    int i, j;
    //Checking in row and column
    for(i=0; i<9; i++)
    {
        if(grid[row][i] == num || grid[i][col] == num)
            return 0; //Invalid number
    }

    //Checking in block
    int r = row - row%3;
    int c = col - col%3;
    for(i=r; i<r+3; i++)
    {
        for(j=c; j<c+3; j++)
        {
            if(grid[i][j] == num)
                return 0;
        }
    }

    return 1; //Valid number
}

//Function to solve the Sudoku using backtracking
int solveSudoku()
{
    int row, col, num;
    if(isComplete()) //if the Sudoku is already complete
        return 1;

    for(row=0; row<9; row++)
    {
        for(col=0; col<9; col++)
        {
            if(grid[row][col] == 0) //if the cell is empty
            {
                for(num=1; num<=9; num++) //try each number one by one
                {
                    if(isValid(row, col, num)) //if number is valid in the given cell
                    {
                        grid[row][col] = num; //fill the cell with the number
                        if(solveSudoku()) //if the next call to solve the Sudoku returns 1
                            return 1;
                        grid[row][col] = 0; //undo the current cell for next try
                    }
                }
                return 0; //all numbers tried, none found valid
            }
        }
    }
    return 0; //unreachable
}

//Function to print the Sudoku grid
int printGrid()
{
    int i, j;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

//Main function to test the Sudoku solver
int main()
{
    int i, j;
    printf("Enter the Sudoku grid (0 for empty cells):\n");
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    if(!solveSudoku())
    {
        printf("No solution exists.\n");
        return 0;
    }

    printf("Sudoku solved successfully:\n");
    printGrid();
    return 0;
}