//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a 2D array to store the game board
    int board[6][6] = {{0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0}};

    // Place the starting pieces on the board
    board[2][2] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    // Simulate the game of life
    for (int i = 0; i < 10; i++)
    {
        // Iterate over the board
        for (int r = 0; r < 6; r++)
        {
            for (int c = 0; c < 6; c++)
            {
                // Calculate the number of living neighbors
                int neighbors = 0;
                if (board[r-1][c] == 1) neighbors++;
                if (board[r+1][c] == 1) neighbors++;
                if (board[r][c-1] == 1) neighbors++;
                if (board[r][c+1] == 1) neighbors++;

                // Apply the rules of life
                if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
                if (board[r][c] == 1 && (neighbors < 2 || neighbors > 3)) board[r][c] = 0;
            }
        }
    }

    // Print the final board
    for (int r = 0; r < 6; r++)
    {
        for (int c = 0; c < 6; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    return 0;
}