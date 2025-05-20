//FormAI DATASET v1.0 Category: Sudoku solver ; Style: standalone
#include <stdio.h>

int grid[9][9];

/*Checks if a number is in a row*/
int row_present(int row, int num)
{
    for(int i = 0; i < 9; i++)
    {
        if(grid[row][i] == num)
            return 1;
    }
    return 0;
}

/*Checks if a number is in a column*/
int column_present(int col, int num)
{
    for(int i = 0; i < 9; i++)
    {
        if(grid[i][col] == num)
            return 1;
    }
    return 0;
}

/*Checks if a number is in a 3x3 sub-grid*/
int subgrid_present(int row, int col, int num)
{
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for(int i = start_row; i < start_row + 3; i++)
    {
        for(int j = start_col; j < start_col + 3; j++)
        {
            if(grid[i][j] == num)
                return 1;
        }
    }
    return 0;
}

/*Checks if a number is valid for a cell*/
int is_valid(int row, int col, int num)
{
    return !row_present(row, num) && !column_present(col, num) && !subgrid_present(row, col, num);
}

/*Finds the next empty cell*/
int next_empty(int *row, int *col)
{
    for(*row = 0; *row < 9; (*row)++)
    {
        for(*col = 0; *col < 9; (*col)++)
        {
            if(grid[*row][*col] == 0)
                return 1;
        }
    }
    return 0;
}

/*Sudoku solving algorithm*/
int solve()
{
    int row, col;
    if(!next_empty(&row, &col))
        return 1;
    for(int num = 1; num <= 9; num++)
    {
        if(is_valid(row, col, num))
        {
            grid[row][col] = num;
            if(solve())
                return 1;
            grid[row][col] = 0;
        }
    }
    return 0;
}

/*Prints the solved Sudoku grid*/
void print_grid()
{
    printf("Sudoku solved successfully!\n");
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

/*Main function*/
int main()
{
    printf("Enter the Sudoku grid:\n");
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }
    if(solve())
        print_grid();
    else
        printf("Failed to solve Sudoku!");
    return 0;
}