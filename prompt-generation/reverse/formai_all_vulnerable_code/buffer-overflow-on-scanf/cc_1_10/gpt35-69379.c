//FormAI DATASET v1.0 Category: Checkers Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// Function to print the board
void printBoard(char board[SIZE][SIZE])
{
    printf("   ");
    for(int i=0; i<SIZE; i++)
    {
        printf("%d ", i+1);
    }
    printf("\n");
    for(int i=0; i<SIZE; i++)
    {
        printf("%d ", i+1);
        for(int j=0; j<SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the board
void initializeBoard(char board[SIZE][SIZE])
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            if(i % 2 == 0)
            {
                if(j % 2 == 0)
                {
                    board[i][j] = '_';
                }
                else
                {
                    board[i][j] = 'O';
                }
            }
            else
            {
                if(j % 2 == 0)
                {
                    board[i][j] = 'O';
                }
                else
                {
                    board[i][j] = '_';
                }
            }
        }
    }
}

// Function to play the game
void playGame(char board[SIZE][SIZE])
{
    int row, col, rowDest, colDest;
    
    while(1)
    {
        printBoard(board);
        
        printf("Enter the position of the piece you wish to move (row col): ");
        scanf("%d %d", &row, &col);
        
        printf("Enter the position where you want to move the piece (row col): ");
        scanf("%d %d", &rowDest, &colDest);
        
        // Check if the move is valid
        if(abs(rowDest-row) == 1 && abs(colDest-col) == 1 && board[rowDest][colDest] == '_')
        {
            // Move the piece
            board[rowDest][colDest] = board[row][col];
            board[row][col] = '_';
        }
        else
        {
            printf("Invalid move.\n");
        }
    }
}

int main()
{
    char board[SIZE][SIZE];
    
    initializeBoard(board);
    playGame(board);
    
    return 0;
}