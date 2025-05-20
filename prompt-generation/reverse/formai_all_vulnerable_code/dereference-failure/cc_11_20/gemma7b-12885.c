//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array to store the game board
    int **board = (int **)malloc(5 * sizeof(int *));
    for (int i = 0; i < 5; i++)
    {
        board[i] = (int *)malloc(5 * sizeof(int));
    }

    // Initialize the game board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Print the game board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Calculate the next generation of the game board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int numNeighbors = 0;
            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    if (board[i + r][j + c] == 1)
                    {
                        numNeighbors++;
                    }
                }
            }

            if (board[i][j] == 1 && numNeighbors < 2)
            {
                board[i][j] = 0;
            }
            else if (board[i][j] == 0 && numNeighbors == 3)
            {
                board[i][j] = 1;
            }
        }
    }

    // Print the next generation of the game board
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < 5; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}