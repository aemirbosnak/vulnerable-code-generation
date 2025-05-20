//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int main()
{
    int **board = NULL;
    int size = MAX_SIZE;

    board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        board[i] = (int *)malloc(size * sizeof(int));
    }

    // Initialize the board with random values
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Game loop
    int generation = 0;
    while (1)
    {
        // Calculate the next generation
        int **next_board = (int **)malloc(size * sizeof(int *));
        for (int i = 0; i < size; i++)
        {
            next_board[i] = (int *)malloc(size * sizeof(int));
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int neighbors = 0;
                for (int r = -1; r <= 1; r++)
                {
                    for (int c = -1; c <= 1; c++)
                    {
                        if (board[i + r][j + c] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                next_board[i][j] = (neighbors == 2) || (neighbors == 3) ? 1 : 0;
            }
        }

        // Free the previous generation
        for (int i = 0; i < size; i++)
        {
            free(board[i]);
        }
        free(board);

        // Update the board
        board = next_board;

        // Increment the generation
        generation++;

        // Check if the game is over
        if (generation >= 10)
        {
            break;
        }
    }

    // Print the final board
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}