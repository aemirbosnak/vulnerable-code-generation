//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int **board = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            board[i][j] = 0;
        }
    }

    // Create a random pattern
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;
    board[7][5] = 1;

    // Simulate the Game of Life
    for (int t = 0; t < 20; t++)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                int neighbors = 0;
                if (board[i - 1][j] == 1) neighbors++;
                if (board[i + 1][j] == 1) neighbors++;
                if (board[i][j - 1] == 1) neighbors++;
                if (board[i][j + 1] == 1) neighbors++;

                if (board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
                if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
            }
        }
    }

    // Print the final board
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}