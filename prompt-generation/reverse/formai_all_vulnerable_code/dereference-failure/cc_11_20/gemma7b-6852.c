//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

int main()
{
    int **board = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++)
    {
        board[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            board[i][j] = 0;
        }
    }

    // Play the game
    int generation = 0;
    while (1)
    {
        // Draw the board
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Calculate the next generation
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                int alive = 0;
                // Check the neighbors
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (x == 0 && y == 0)
                            continue;

                        if (board[i + x][j + y] == 1)
                            alive++;
                    }
                }

                // Apply the rules
                if (board[i][j] == 1 && alive < 2)
                    board[i][j] = 0;
                else if (board[i][j] == 0 && alive == 3)
                    board[i][j] = 1;
            }
        }

        // Increment the generation
        generation++;

        // Check if the game is over
        if (generation >= 10)
            break;
    }

    // Free the memory
    for (int i = 0; i < HEIGHT; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}