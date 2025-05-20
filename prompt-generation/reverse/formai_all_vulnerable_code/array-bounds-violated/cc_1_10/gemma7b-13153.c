//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void play_game()
{
    int board[MAX][MAX] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
                              {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                              {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    for (int r = 0; r < MAX; r++)
    {
        for (int c = 0; c < MAX; c++)
        {
            int neighbors = 0;

            // Check the number of neighbors
            if (board[r - 1][c] == 1) neighbors++;
            if (board[r + 1][c] == 1) neighbors++;
            if (board[r][c - 1] == 1) neighbors++;
            if (board[r][c + 1] == 1) neighbors++;

            // Apply the Game of Life rules
            if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            if (board[r][c] == 1 && (neighbors < 2 || neighbors > 3)) board[r][c] = 0;
        }
    }

    // Print the updated board
    for (int r = 0; r < MAX; r++)
    {
        for (int c = 0; c < MAX; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    play_game();
    return 0;
}