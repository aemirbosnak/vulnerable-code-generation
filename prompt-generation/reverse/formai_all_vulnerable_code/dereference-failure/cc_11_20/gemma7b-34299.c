//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Game of Life rules
    for (int t = 0; t < 10; t++)
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            for (int j = 0; j < MAX_SIZE; j++)
            {
                int neighbors = 0;
                // Check the number of neighbors
                if (i - 1 >= 0) neighbors++;
                if (i + 1 < MAX_SIZE) neighbors++;
                if (j - 1 >= 0) neighbors++;
                if (j + 1 < MAX_SIZE) neighbors++;

                // Apply the rules
                if (board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
                if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
            }
        }

        // Print the board
        for (int i = 0; i < MAX_SIZE; i++)
        {
            for (int j = 0; j < MAX_SIZE; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Pause
        sleep(1);
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}