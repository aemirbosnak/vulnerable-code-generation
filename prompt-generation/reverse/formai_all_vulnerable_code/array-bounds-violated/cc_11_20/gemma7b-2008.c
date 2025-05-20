//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a 2D array to store the game board
    int board[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Iterate over the game board and check for living cells
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            int num_neighbors = 0;

            // Check the four adjacent cells
            if (board[r-1][c] == 1) num_neighbors++;
            if (board[r+1][c] == 1) num_neighbors++;
            if (board[r][c-1] == 1) num_neighbors++;
            if (board[r][c+1] == 1) num_neighbors++;

            // If the cell is alive and has less than 2 neighbors, it dies
            if (board[r][c] == 1 && num_neighbors < 2) board[r][c] = 0;

            // If the cell is dead and has exactly 3 neighbors, it comes back to life
            if (board[r][c] == 0 && num_neighbors == 3) board[r][c] = 1;
        }
    }

    // Print the updated game board
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    return 0;
}