//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include <stdlib.h>
#include <time.h>

#define WIDTH 5
#define HEIGHT 5

#define EMPTY 0
#define LIVE 1

int main()
{
    int **board = (int**)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++)
    {
        board[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            board[i][j] = EMPTY;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Randomly assign some cells to live
    for (int i = 0; i < 10; i++)
    {
        board[rand() % HEIGHT][rand() % WIDTH] = LIVE;
    }

    // Game of Life rules
    for (int iter = 0; iter < 10; iter++)
    {
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                int neighbors = 0;
                // Check the neighbors
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (x == 0 && y == 0) continue;
                        if (board[i + x][j + y] == LIVE) neighbors++;
                    }
                }

                // Apply the rules
                if (board[i][j] == LIVE && neighbors < 2) board[i][j] = EMPTY;
                else if (board[i][j] == EMPTY && neighbors == 3) board[i][j] = LIVE;
            }
        }
    }

    // Print the final board
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < HEIGHT; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}