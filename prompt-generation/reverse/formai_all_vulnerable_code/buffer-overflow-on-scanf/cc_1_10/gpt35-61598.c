//FormAI DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include <stdio.h>

#define N 9

int board[N][N];

// Function to check if a number is already present in the column
int is_col_safe(int col, int num)
{
    for(int i=0; i<N; i++)
    {
        if(board[i][col] == num)
        {
            return 0; // number already present in column
        }
    }
    return 1; // number not present in column
}

// Function to check if a number is already present in the row
int is_row_safe(int row, int num)
{
    for(int i=0; i<N; i++)
    {
        if(board[row][i] == num)
        {
            return 0; // number already present in row
        }
    }
    return 1; // number not present in row
}

// Function to check if a number is already present in the current 3x3 box
int is_box_safe(int row, int col, int num)
{
    int box_row_start = row - row%3;
    int box_col_start = col - col%3;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[box_row_start+i][box_col_start+j] == num)
            {
                return 0; // number already present in 3x3 box
            }
        }
    }
    return 1; // number not present in 3x3 box
}

// Function to check if it is safe to insert a number in the current position
int is_safe(int row, int col, int num)
{
    return is_row_safe(row, num) && is_col_safe(col, num) && is_box_safe(row, col, num);
}

// Function to print the sudoku board
void print_board()
{
    printf("\n-------------------------\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%d ", board[i][j]);
            if((j+1)%3 == 0)
            {
                printf("| ");
            }
        }
        if((i+1)%3 == 0)
        {
            printf("\n-------------------------");
        }
        printf("\n");
    }
}

// Function to solve the sudoku board using recursion and backtracking
int solve_sudoku(int row, int col)
{
    if(row == N-1 && col == N)
    {
        return 1; // board is completely filled
    }

    if(col == N)
    {
        row++;
        col = 0;
    }

    if(board[row][col] > 0) // skip cell already filled
    {
        return solve_sudoku(row, col+1);
    }

    for(int num=1; num<=N; num++)
    {
        if(is_safe(row, col, num))
        {
            board[row][col] = num;
            if(solve_sudoku(row, col+1))
            {
                return 1;
            }
        }
        board[row][col] = 0;
    }

    return 0;
}

int main()
{
    printf("Enter the Sudoku board (use 0 to represent empty cells):\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    printf("\n\nThe Sudoku board entered is:\n");
    print_board();

    if(solve_sudoku(0, 0))
    {
        printf("\n\nThe solved Sudoku board is:\n");
        print_board();
    }
    else
    {
        printf("\n\nNo solution exists for the given Sudoku board!\n");
    }

    return 0;
}