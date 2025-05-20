//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Place the initial organisms
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    // Simulate the game of life
    int generation = 0;
    while (!board[MAX_SIZE - 1][MAX_SIZE - 1] && generation < 10)
    {
        generation++;

        // Calculate the number of neighbors for each organism
        for (int i = 0; i < MAX_SIZE; i++)
        {
            for (int j = 0; j < MAX_SIZE; j++)
            {
                int num_neighbors = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (board[i + x][j + y] == 1)
                        {
                            num_neighbors++;
                        }
                    }
                }

                // Apply the rules of life
                if (board[i][j] == 1)
                {
                    if (num_neighbors < 2)
                    {
                        board[i][j] = 0;
                    }
                    else if (num_neighbors > 3)
                    {
                        board[i][j] = 0;
                    }
                }
                else if (num_neighbors == 3)
                {
                    board[i][j] = 1;
                }
            }
        }
    }

    // Print the final board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}