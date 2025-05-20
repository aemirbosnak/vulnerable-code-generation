//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main()
{
    int board[MAX][MAX];
    int x, y, i, j, n;

    // Initialize the board
    for (x = 0; x < MAX; x++)
    {
        for (y = 0; y < MAX; y++)
        {
            board[x][y] = 0;
        }
    }

    // Randomly fill the board with water
    srand(time(NULL));
    n = rand() % MAX;
    board[n][n] = 1;

    // Percolation simulation
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (board[i][j] == 1)
            {
                // Check the four neighbors
                if (board[i-1][j] == 0 && board[i+1][j] == 0 && board[i][j-1] == 0 && board[i][j+1] == 0)
                {
                    board[i][j] = 0;
                }
            }
        }
    }

    // Print the final board
    for (x = 0; x < MAX; x++)
    {
        for (y = 0; y < MAX; y++)
        {
            printf("%d ", board[x][y]);
        }
        printf("\n");
    }

    return 0;
}