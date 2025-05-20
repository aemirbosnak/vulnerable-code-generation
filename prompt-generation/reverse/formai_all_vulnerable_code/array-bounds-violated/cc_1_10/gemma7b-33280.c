//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 5

#define EMPTY 0
#define FILLED 1

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
                              EMPTY, EMPTY, FILLED, EMPTY, EMPTY,
                              EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
                              EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,
                              EMPTY, EMPTY, EMPTY, EMPTY, EMPTY };

    int x, y;

    // Percolation algorithm
    for (x = 0; x < BOARD_SIZE; x++)
    {
        for (y = 0; y < BOARD_SIZE; y++)
        {
            if (board[x][y] == FILLED)
            {
                // Check if the cell above is empty
                if (board[x][y - 1] == EMPTY)
                {
                    board[x][y - 1] = FILLED;
                }

                // Check if the cell to the right is empty
                if (board[x + 1][y] == EMPTY)
                {
                    board[x + 1][y] = FILLED;
                }
            }
        }
    }

    // Print the board
    for (x = 0; x < BOARD_SIZE; x++)
    {
        for (y = 0; y < BOARD_SIZE; y++)
        {
            printf("%d ", board[x][y]);
        }
        printf("\n");
    }

    return 0;
}