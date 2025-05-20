//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int board[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int generation = 0;

    while (1)
    {
        printf("Generation: %d\n", generation);

        for (int r = 0; r < MAX; r++)
        {
            for (int c = 0; c < MAX; c++)
            {
                int neighbors = 0;

                // Count the number of neighbors
                if (board[r - 1][c] == 1) neighbors++;
                if (board[r + 1][c] == 1) neighbors++;
                if (board[r][c - 1] == 1) neighbors++;
                if (board[r][c + 1] == 1) neighbors++;

                // Apply the Game of Life rules
                if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        generation++;

        // Print the board
        for (int r = 0; r < MAX; r++)
        {
            for (int c = 0; c < MAX; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Check if the game is over
        if (board[0][0] == 0 && board[MAX - 1][MAX - 1] == 0) break;
    }

    return 0;
}