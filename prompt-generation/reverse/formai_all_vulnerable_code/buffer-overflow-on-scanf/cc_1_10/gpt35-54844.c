//FormAI DATASET v1.0 Category: Sudoku solver ; Style: statistical
#include <stdio.h>

int board[9][9];

int CheckRow(int row, int num)
{
    int col;
    for(col=0; col<9; col++)
    {
        if(board[row][col]==num)
        {
            return 1;
        }
    }
    return 0;
}

int CheckColumn(int col, int num)
{
    int row;
    for(row=0; row<9; row++)
    {
        if(board[row][col]==num)
        {
            return 1;
        }
    }
    return 0;
}

int CheckBox(int row, int col, int num)
{
    int box_row, box_col;
    for(box_row=0; box_row<3; box_row++)
    {
        for(box_col=0; box_col<3; box_col++)
        {
            if(board[row+box_row][col+box_col]==num)
            {
                return 1;
            }
        }
    }
    return 0;
}

int isSafe(int row, int col, int num)
{
    return !CheckRow(row,num) && !CheckColumn(col,num) && !CheckBox(row-row%3,col-col%3,num);
}

int Solver()
{
    int row,col,num;
    for(row=0; row<9; row++)
    {
        for(col=0; col<9; col++)
        {
            if(board[row][col]==0)
            {
                for(num=1; num<=9; num++)
                {
                    if(isSafe(row, col, num))
                    {
                        board[row][col]=num;
                        if(Solver()) return 1;
                        board[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

void SudokuSolver()
{
    int row,col;
    printf("Enter the Sudoku Board: \n");
    for(row=0; row<9; row++)
    {
        for(col=0; col<9; col++)
        {
            scanf("%d",&board[row][col]);
        }
    }
    if(Solver())
    {
        printf("Solution Found: \n");
        for(row=0; row<9; row++)
        {
            for(col=0; col<9; col++)
            {
                printf("%d ",board[row][col]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("No Solution Found!! \n");
    }
}

int main()
{
    SudokuSolver();
    return 0;
}