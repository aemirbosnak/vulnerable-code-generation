//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: peaceful
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

int main()
{
    int **board = (int **)malloc(WIDTH * sizeof(int *));
    for (int i = 0; i < WIDTH; i++)
    {
        board[i] = (int *)malloc(HEIGHT * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            board[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Place some random cells on the board
    for (int i = 0; i < 10; i++)
    {
        board[rand() % WIDTH][rand() % HEIGHT] = 1;
    }

    // Simulate life for 10 generations
    for (int generation = 0; generation < 10; generation++)
    {
        // Calculate the next generation
        for (int i = 0; i < WIDTH; i++)
        {
            for (int j = 0; j < HEIGHT; j++)
            {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (x == 0 && y == 0)
                        {
                            continue;
                        }
                        if (board[i + x][j + y] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                if (board[i][j] == 1)
                {
                    if (neighbors < 2)
                    {
                        board[i][j] = 0;
                    }
                }
                else
                {
                    if (neighbors == 3)
                    {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }

    // Print the final board
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < WIDTH; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}