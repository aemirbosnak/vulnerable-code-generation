//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20

#define ALIVE 1
#define DEAD 0

int main()
{
    int **board = NULL;
    int i, j, k, l, seed, generation = 0;
    char message[200];

    // Allocate memory for the board
    board = (int **)malloc(BOARD_SIZE * sizeof(int *));
    for (i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
    }

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the board
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = DEAD;
        }
    }

    // Randomly assign some cells to alive
    for (k = 0; k < 10; k++)
    {
        i = rand() % BOARD_SIZE;
        j = rand() % BOARD_SIZE;
        board[i][j] = ALIVE;
    }

    // Game loop
    while (generation < 10)
    {
        for (i = 0; i < BOARD_SIZE; i++)
        {
            for (j = 0; j < BOARD_SIZE; j++)
            {
                int alive_neighbors = 0;
                for (l = -1; l <= 1; l++)
                {
                    for (k = -1; k <= 1; k++)
                    {
                        if (board[i + l][j + k] == ALIVE)
                        {
                            alive_neighbors++;
                        }
                    }
                }

                if (board[i][j] == ALIVE && alive_neighbors < 2)
                {
                    board[i][j] = DEAD;
                }
                else if (board[i][j] == DEAD && alive_neighbors == 3)
                {
                    board[i][j] = ALIVE;
                }
            }
        }

        generation++;
    }

    // Print the final board
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the board
    for (i = 0; i < BOARD_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}