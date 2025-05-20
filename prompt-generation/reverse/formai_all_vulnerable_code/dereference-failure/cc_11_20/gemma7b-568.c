//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **board = NULL;
    int i, j, k, l;
    time_t t;

    // Allocate memory for the board
    board = (int **)malloc(HEIGHT * sizeof(int *));
    for (i = 0; i < HEIGHT; i++)
    {
        board[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Initialize the board
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            board[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create the initial patterns
    for (k = 0; k < 10; k++)
    {
        for (l = 0; l < 5; l++)
        {
            board[rand() % HEIGHT][rand() % WIDTH] = 1;
        }
    }

    // Start the game loop
    t = time(NULL);
    while (time(NULL) - t < 10)
    {
        // Calculate the next generation
        for (i = 0; i < HEIGHT; i++)
        {
            for (j = 0; j < WIDTH; j++)
            {
                int neighbors = 0;
                for (k = -1; k <= 1; k++)
                {
                    for (l = -1; l <= 1; l++)
                    {
                        if (board[i + k][j + l] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

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

        // Print the board
        for (i = 0; i < HEIGHT; i++)
        {
            for (j = 0; j < WIDTH; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Sleep for a while
        sleep(1);
    }

    // Free the memory
    for (i = 0; i < HEIGHT; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}