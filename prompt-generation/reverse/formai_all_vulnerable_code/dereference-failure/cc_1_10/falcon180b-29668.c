//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

#define SIZE 9
#define EMPTY 0
#define NUM 1

// Function to check if the number is valid
int isValid(int **board, int row, int col, int num)
{
    int i, j;
    for(i=0; i<SIZE; i++)
    {
        if(board[row][i] == num)
            return 0;
    }
    for(i=0; i<SIZE; i++)
    {
        if(board[i][col] == num)
            return 0;
    }
    int boxRow = (row/3)*3;
    int boxCol = (col/3)*3;
    for(i=boxRow; i<boxRow+3; i++)
    {
        for(j=boxCol; j<boxCol+3; j++)
        {
            if(board[i][j] == num)
                return 0;
        }
    }
    return 1;
}

// Function to solve the Sudoku
int solveSudoku(int **board)
{
    int row, col;
    for(row=0; row<SIZE; row++)
    {
        for(col=0; col<SIZE; col++)
        {
            if(board[row][col] == EMPTY)
            {
                int num = 1;
                while(isValid(board, row, col, num))
                {
                    num++;
                }
                board[row][col] = num;
            }
        }
    }
    return 1;
}

// Function to print the Sudoku
void printSudoku(int **board)
{
    int row, col;
    for(row=0; row<SIZE; row++)
    {
        for(col=0; col<SIZE; col++)
        {
            if(board[row][col] == EMPTY)
                printf(" ");
            else
                printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

// Function to check if the Sudoku is solved
int isSolved(int **board)
{
    int row, col;
    for(row=0; row<SIZE; row++)
    {
        for(col=0; col<SIZE; col++)
        {
            if(board[row][col] == EMPTY)
                return 0;
        }
    }
    return 1;
}

int main()
{
    int **board;
    int row, col;
    srand(time(NULL));
    board = (int **)malloc(SIZE*sizeof(int *));
    for(row=0; row<SIZE; row++)
    {
        board[row] = (int *)malloc(SIZE*sizeof(int));
        for(col=0; col<SIZE; col++)
        {
            board[row][col] = rand()%9+1;
        }
    }
    printf("Initial Sudoku:\n");
    printSudoku(board);
    solveSudoku(board);
    printf("\nSolved Sudoku:\n");
    printSudoku(board);
    if(isSolved(board))
        printf("\nSudoku is solved!\n");
    else
        printf("\nSudoku is not solved!\n");
    return 0;
}