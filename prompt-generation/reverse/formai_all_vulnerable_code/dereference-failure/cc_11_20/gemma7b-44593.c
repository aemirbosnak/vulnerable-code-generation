//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

int main()
{
    int **board = NULL;
    int i, j, k, l, r, c;
    int seed;

    // Allocate memory for the game board
    board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the game board
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Set the seed for the random number generator
    srand(time(NULL));

    // Create a random pattern on the game board
    for (k = 0; k < 10; k++)
    {
        i = rand() % MAX_SIZE;
        j = rand() % MAX_SIZE;
        board[i][j] = 1;
    }

    // Display the game board
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Simulate the game of life
    for (l = 0; l < 10; l++)
    {
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                r = (i - 1) % MAX_SIZE;
                c = (j - 1) % MAX_SIZE;
                if (board[r][c] == 1)
                {
                    board[i][j] = 1;
                }
                else if (board[r][c] == 0)
                {
                    board[i][j] = 0;
                }
            }
        }

        // Display the game board
        for (i = 0; i < MAX_SIZE; i++)
        {
            for (j = 0; j < MAX_SIZE; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    // Free the memory allocated for the game board
    for (i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}