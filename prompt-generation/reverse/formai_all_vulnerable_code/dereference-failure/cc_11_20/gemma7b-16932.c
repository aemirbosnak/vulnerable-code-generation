//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **board = NULL;
    int size = 0;

    board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for(int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for(int i = 0; i < MAX_SIZE; i++)
    {
        for(int j = 0; j < MAX_SIZE; j++)
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
    board[7][6] = 1;

    // Play the Game of Life
    for(int generation = 0; generation < 10; generation++)
    {
        // Calculate the next generation
        for(int i = 0; i < MAX_SIZE; i++)
        {
            for(int j = 0; j < MAX_SIZE; j++)
            {
                int numNeighbors = 0;
                for(int x = -1; x <= 1; x++)
                {
                    for(int y = -1; y <= 1; y++)
                    {
                        if(board[i + x][j + y] == 1)
                        {
                            numNeighbors++;
                        }
                    }
                }

                if(numNeighbors < 2)
                {
                    board[i][j] = 0;
                }
                else if(numNeighbors == 2)
                {
                    board[i][j] = 1;
                }
            }
        }

        // Print the board
        for(int i = 0; i < MAX_SIZE; i++)
        {
            for(int j = 0; j < MAX_SIZE; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        printf("Generation %d:\n", generation);
    }

    // Free the memory
    for(int i = 0; i < MAX_SIZE; i++)
    {
        for(int j = 0; j < MAX_SIZE; j++)
        {
            free(board[i][j]);
        }
        free(board[i]);
    }

    free(board);

    return 0;
}