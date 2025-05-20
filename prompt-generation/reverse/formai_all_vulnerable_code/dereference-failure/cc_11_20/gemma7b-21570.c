//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main()
{
    int **board = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            board[i][j] = 0;
        }
    }

    // Game loop
    int generation = 0;
    while (1)
    {
        // Print the board
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Calculate the next generation
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                int neighbors = 0;
                // Check the number of neighbors
                if (i > 0) neighbors++;
                if (i < MAX - 1) neighbors++;
                if (j > 0) neighbors++;
                if (j < MAX - 1) neighbors++;

                // Apply the rules of survival and reproduction
                if (board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
                if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
            }
        }

        // Increment the generation
        generation++;

        // Check if the game is over
        if (generation > 10) break;
    }

    // Free the memory
    for (int i = 0; i < MAX; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}