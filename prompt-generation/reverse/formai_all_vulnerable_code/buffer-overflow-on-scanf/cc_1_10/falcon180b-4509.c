//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 9

// Function to check whether a number is valid or not
int isValid(int board[N][N], int row, int col, int num)
{
    // Check row and column
    for(int i=0; i<N; i++)
    {
        if(board[row][i] == num || board[i][col] == num)
            return 0;
    }

    // Check 3x3 box
    int startRow = (row/3)*3;
    int startCol = (col/3)*3;
    for(int i=startRow; i<startRow+3; i++)
    {
        for(int j=startCol; j<startCol+3; j++)
        {
            if(board[i][j] == num)
                return 0;
        }
    }
    return 1;
}

// Function to solve the Sudoku puzzle recursively
void solveSudoku(int board[N][N], int row, int col)
{
    // Check if we have reached the end of the board
    if(row == N)
    {
        row = 0;
        col++;
        if(col == N)
            printf("\nSolution found!\n");
        else
            solveSudoku(board, 0, col);
    }
    // Check if the current cell is empty
    else if(board[row][col] == 0)
    {
        // Try all numbers from 1 to 9
        for(int num=1; num<=9; num++)
        {
            // If the number is valid, fill the cell and move to the next one
            if(isValid(board, row, col, num))
            {
                board[row][col] = num;
                solveSudoku(board, row, col+1);
            }
        }
        // If no number is valid, backtrack to the previous cell
        board[row][col] = 0;
        solveSudoku(board, row, col-1);
    }
    // If the current cell is not empty, move to the next one
    else
        solveSudoku(board, row, col+1);
}

// Function to print the Sudoku board
void printBoard(int board[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Main function to read the Sudoku puzzle from the user and solve it
int main()
{
    int board[N][N];
    printf("Enter the Sudoku puzzle:\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    srand(time(NULL));
    solveSudoku(board, 0, 0);
    return 0;
}