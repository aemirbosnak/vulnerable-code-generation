//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main()
{
    int board[ROWS][COLS] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                              {0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                              {0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int r, c, i, seed;

    // Seed the random number generator
    seed = time(NULL);
    srand(seed);

    // Percolation simulation
    for (i = 0; i < 1000; i++)
    {
        r = rand() % ROWS;
        c = rand() % COLS;

        // If the cell is empty and the neighbor cells are full,
        // then the cell becomes full.
        if (board[r][c] == 0 && board[r-1][c] == 1 && board[r+1][c] == 1 && board[r][c-1] == 1 && board[r][c+1] == 1)
        {
            board[r][c] = 1;
        }
    }

    // Print the board
    for (r = 0; r < ROWS; r++)
    {
        for (c = 0; c < COLS; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    return 0;
}