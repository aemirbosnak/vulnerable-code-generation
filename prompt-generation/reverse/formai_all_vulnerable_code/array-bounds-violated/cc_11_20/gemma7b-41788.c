//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[20][20] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Game of Life rules
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;
    board[7][5] = 1;

    int gen = 0;

    // Simulate generations
    while (gen < 10)
    {
        int i, j;

        // Calculate the next generation
        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 20; j++)
            {
                int neighbors = 0;

                // Count the number of neighbors
                if (board[i-1][j] == 1) neighbors++;
                if (board[i+1][j] == 1) neighbors++;
                if (board[i][j-1] == 1) neighbors++;
                if (board[i][j+1] == 1) neighbors++;

                // Apply the Game of Life rules
                if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) board[i][j] = 0;
                else if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
            }
        }

        // Print the board
        for (i = 0; i < 20; i++)
        {
            for (j = 0; j < 20; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        gen++;
    }

    return 0;
}