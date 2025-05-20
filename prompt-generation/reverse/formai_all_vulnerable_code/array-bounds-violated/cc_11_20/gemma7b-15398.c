//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int board[MAX_SIZE][MAX_SIZE] = {0};
    int i, j, k, l;

    // Initialize the game board
    board[0][0] = 1;
    board[0][1] = 1;
    board[1][0] = 1;
    board[1][1] = 1;
    board[2][2] = 1;

    // Simulate the game of life
    for (k = 0; k < 5; k++)
    {
        for (l = 0; l < 5; l++)
        {
            int neighbors = 0;
            for (i = -1; i <= 1; i++)
            {
                for (j = -1; j <= 1; j++)
                {
                    if (board[i][j] && (i != 0 || j != 0))
                    {
                        neighbors++;
                    }
                }
            }

            if (board[k][l] && neighbors < 2)
            {
                board[k][l] = 0;
            }
            else if (board[k][l] && neighbors > 3)
            {
                board[k][l] = 0;
            }
            else
            {
                board[k][l] = 1;
            }
        }
    }

    // Print the final game board
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