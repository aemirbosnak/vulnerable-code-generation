//FormAI DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printBoard(int board[ROWS][COLS], int revealed[ROWS][COLS])
{
    for(int i = 0; i<ROWS; i++)
    {
        for(int j = 0; j<COLS; j++)
        {
            if(revealed[i][j] == 0)
            {
                printf("X ");
            }
            else
            {
                printf("%d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

void revealCell(int board[ROWS][COLS], int revealed[ROWS][COLS], int row, int col)
{
    revealed[row][col] = 1;
}

int checkForMatch(int board[ROWS][COLS], int revealed[ROWS][COLS], int row1, int col1, int row2, int col2)
{
    if(board[row1][col1] == board[row2][col2])
    {
        return 1;
    }
    else
    {
        revealed[row1][col1] = 0;
        revealed[row2][col2] = 0;
        return 0;
    }
}

int checkForWin(int board[ROWS][COLS], int revealed[ROWS][COLS])
{
    for(int i = 0; i<ROWS; i++)
    {
        for(int j = 0; j<COLS; j++)
        {
            if(revealed[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int board[ROWS][COLS] = {{1,2,3,4}, {5,6,7,8}, {1,2,3,4}, {5,6,7,8}};
    int revealed[ROWS][COLS] = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
    int numMoves = 0;
    int row1, col1, row2, col2;
    srand(time(NULL));
    
    // Shuffle board
    for(int i = 0; i < ROWS; i++) 
    {
        for(int j = 0; j < COLS; j++) 
        {
            int randRow = rand() % ROWS;
            int randCol = rand() % COLS;
            int temp = board[i][j];
            board[i][j] = board[randRow][randCol];
            board[randRow][randCol] = temp;
        }
    }
    
    while(!checkForWin(board, revealed))
    {
        printf("Number of moves: %d \n", numMoves);
        printBoard(board, revealed);
        printf("Enter the row and column of the first cell you want to flip (e.g. 1 2): ");
        scanf("%d %d", &row1, &col1);
        revealCell(board, revealed, row1-1, col1-1);
        printBoard(board, revealed);
        printf("Enter the row and column of the second cell you want to flip (e.g. 3 4): ");
        scanf("%d %d", &row2, &col2);
        revealCell(board, revealed, row2-1, col2-1);
        numMoves++;
        if(checkForMatch(board, revealed, row1-1, col1-1, row2-1, col2-1))
        {
            printf("Match found!\n");
        }
        else
        {
            printf("No match...\n");
        }
    }
    printf("Congratulations! You won in %d moves.", numMoves);
    return 0;
}