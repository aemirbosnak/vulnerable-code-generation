//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 5

int main()
{
    int board[MAX_SIZE][MAX_SIZE];
    int i, j, k, l;
    int live_cells = 0;
    int neighbor_count[MAX_SIZE][MAX_SIZE];

    // Initialize the board
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create a random number of live cells
    live_cells = rand() % MAX_SIZE * MAX_SIZE;

    // Place the live cells
    for (k = 0; k < live_cells; k++)
    {
        i = rand() % MAX_SIZE;
        j = rand() % MAX_SIZE;
        board[i][j] = 1;
    }

    // Calculate the number of neighbors for each cell
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            neighbor_count[i][j] = 0;
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (board[i + k][j + l] == 1)
                    {
                        neighbor_count[i][j]++;
                    }
                }
            }
        }
    }

    // Apply the Game of Life rules
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (board[i][j] == 1)
            {
                if (neighbor_count[i][j] < 2 || neighbor_count[i][j] > 3)
                {
                    board[i][j] = 0;
                }
            }
            else
            {
                if (neighbor_count[i][j] == 3)
                {
                    board[i][j] = 1;
                }
            }
        }
    }

    // Print the board
    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}