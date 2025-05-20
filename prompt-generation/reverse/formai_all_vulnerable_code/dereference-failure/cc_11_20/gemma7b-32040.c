//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int main()
{
    int **board = NULL;
    int size = MAX_SIZE;

    // Allocate memory for the game board
    board = (int **)malloc(size * sizeof(int *) + size);
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int) + size);
    }

    // Initialize the game board
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create a random pattern of living cells
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Simulate the game of life
    for (int t = 0; t < 10; t++)
    {
        // Calculate the number of living neighbors for each cell
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (board[i + x][j + y] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                // Apply the rules of life
                if (board[i][j] == 1 && neighbors < 2)
                {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 0 && neighbors == 3)
                {
                    board[i][j] = 1;
                }
            }
        }

        // Print the game board
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    // Free the memory allocated for the game board
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            free(board[i][j]);
        }
        free(board[i]);
    }
    free(board);

    return 0;
}