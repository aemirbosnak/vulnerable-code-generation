//FormAI DATASET v1.0 Category: Sudoku solver ; Style: satisfied
#include <stdio.h>

int grid[9][9];

//Function to check if the value is present in the row
int present_in_row(int row, int num)
{
    for (int col = 0; col < 9; col++)
    {
        if (grid[row][col] == num)
        {
            return 1;
        }
    }
    return 0;
}

//Function to check if the value is present in the column
int present_in_col(int col, int num)
{
    for (int row = 0; row < 9; row++)
    {
        if (grid[row][col] == num)
        {
            return 1;
        }
    }
    return 0;
}

//Function to check if the value is present in the box
int present_in_box(int row, int col, int num)
{
    int row_start = row - row % 3;
    int col_start = col - col % 3;

    for (int i = row_start; i < row_start + 3; i++)
    {
        for (int j = col_start; j < col_start + 3; j++)
        {
            if (grid[i][j] == num)
            {
                return 1;
            }
        }
    }
    return 0;
}

//Function to check if it is safe to place the number in the given position
int is_safe(int row, int col, int num)
{
    if (!present_in_row(row, num) && !present_in_col(col, num) && !present_in_box(row, col, num))
    {
        return 1;
    }
    return 0;
}

//Function to print the grid
void print_grid()
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

//Function to solve the Sudoku
int solve_sudoku()
{
    int row, col;

    //Check for empty cells and store the row and column values
    int found = 0;
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (grid[row][col] == 0)
            {
                found = 1;
                break;
            }
        }
        if (found == 1)
        {
            break;
        }
    }

    //If all cells are filled, return 1
    if (row == 9 && col == 9)
    {
        return 1;
    }

    //Fill the empty cell with numbers from 1 to 9 and check if it is safe to place it there.
    for (int num = 1; num <= 9; num++)
    {
        if (is_safe(row, col, num))
        {
            grid[row][col] = num;

            //If it is safe, move on to the next cell
            if (solve_sudoku())
            {
                return 1;
            }

            //If it is not safe, backtrack and try a different number
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main()
{
    printf("Enter the Sudoku grid (0 for empty cells):\n");
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            scanf("%d", &grid[row][col]);
        }
    }

    printf("\nSudoku Grid:\n");
    print_grid();

    if (solve_sudoku())
    {
        printf("\nSolution:\n");
        print_grid();
    }
    else
    {
        printf("\nNo solution found");
    }
    return 0;
}