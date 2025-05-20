//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int boardSize = 5;
    int numStains = 3;
    int **board = NULL;
    int i, j, k;
    int stainSize = 2;

    board = (int **)malloc(boardSize * sizeof(int *));
    for(i = 0; i < boardSize; i++)
    {
        board[i] = (int *)malloc(boardSize * sizeof(int));
    }

    // Initialize the board
    for(i = 0; i < boardSize; i++)
    {
        for(j = 0; j < boardSize; j++)
        {
            board[i][j] = 0;
        }
    }

    // Place the stains
    for(k = 0; k < numStains; k++)
    {
        board[rand() % boardSize][rand() % boardSize] = stainSize;
    }

    // Percolation
    for(i = 0; i < boardSize; i++)
    {
        for(j = 0; j < boardSize; j++)
        {
            if(board[i][j] > 0)
            {
                int x, y;
                for(x = i - 1; x <= i + 1 && x < boardSize; x++)
                {
                    for(y = j - 1; y <= j + 1 && y < boardSize; y++)
                    {
                        if(board[x][y] == 0)
                        {
                            board[x][y] = stainSize;
                        }
                    }
                }
            }
        }
    }

    // Print the board
    for(i = 0; i < boardSize; i++)
    {
        for(j = 0; j < boardSize; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    free(board);
    return;
}