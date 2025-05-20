//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complete
#include <stdio.h>

int board[9][9];

void print_board()
{
    printf("\n|---|---|---|---|---|---|---|---|---|\n");
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(j==0)
                printf("|");
            printf(" %d ", board[i][j]);
            if(j==2 || j==5 || j==8)
                printf("|");
        }
        if(i==2 || i==5 || i==8)
            printf("\n|---|---|---|---|---|---|---|---|---|");
        printf("\n");
    }
    printf("|---|---|---|---|---|---|---|---|---|\n");
}

int is_valid(int row, int col, int num)
{
    // check if num already exists in the same row or column
    for(int i=0; i<9; i++)
    {
        if(board[row][i]==num || board[i][col]==num)
            return 0;
    }
    
    // check if num already exists in the same sub-grid
    int sub_row = row - row%3, sub_col = col - col%3;
    for(int i=sub_row; i<sub_row+3; i++)
    {
        for(int j=sub_col; j<sub_col+3; j++)
        {
            if(board[i][j]==num)
                return 0;
        }
    }
    return 1;
}

int solve_sudoku(int row, int col)
{
    if(row == 9)
        return 1;
    
    if(board[row][col] != 0) // cell already has a value
    {
        if(col==8)
            return solve_sudoku(row+1, 0);
        else
            return solve_sudoku(row, col+1);
    }
    
    for(int i=1; i<=9; i++)
    {
        if(is_valid(row, col, i))
        {
            board[row][col] = i;
            if(col==8)
            {
                if(solve_sudoku(row+1, 0))
                    return 1;
            }
            else
            {
                if(solve_sudoku(row, col+1))
                    return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

int main()
{
    printf("Enter the Sudoku board (Use 0 to indicate empty cells):\n\n");
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            scanf("%d", &board[i][j]);
    }
    
    printf("\nThe Sudoku board you entered is:\n");
    print_board();
    
    if(solve_sudoku(0,0))
    {
        printf("\nThe solved Sudoku board is:\n");
        print_board();
    }
    else
        printf("\nNo solution exists for the given Sudoku board.\n");
    
    return 0;
}