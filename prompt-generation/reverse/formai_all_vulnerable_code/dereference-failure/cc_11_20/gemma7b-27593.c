//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **board = NULL;
    int i, j, k, l;

    board = (int**)malloc(MAX_SIZE * sizeof(int*));
    for (i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int*)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board with random values
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Print the initial board
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Game of Life rules
    for (k = 0; k < 10; k++)
    {
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                int neighbors = 0;
                for (l = -1; l <= 1; l++)
                {
                    if (i + l >= 0 && i + l < MAX_SIZE && j - 1 >= 0 && j - 1 < MAX_SIZE)
                    {
                        neighbors += board[i + l][j - 1];
                    }
                }

                if (board[i][j] == 1 && neighbors < 2)
                {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 0 && neighbors == 2)
                {
                    board[i][j] = 1;
                }
            }
        }

        // Print the updated board
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}