//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void play_game()
{
    int board[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0, 1, 0, 0, 1, 0},
                              {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
                              {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                              {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
                              {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            int neighbors = 0;

            // Check the four neighbors
            if (board[row - 1][col] == 1) neighbors++;
            if (board[row + 1][col] == 1) neighbors++;
            if (board[row][col - 1] == 1) neighbors++;
            if (board[row][col + 1] == 1) neighbors++;

            // Apply the Game of Life rules
            if (board[row][col] == 0 && neighbors == 3) board[row][col] = 1;
            if (board[row][col] == 1 && (neighbors < 2 || neighbors > 3)) board[row][col] = 0;
        }
    }

    // Print the updated board
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

int main()
{
    play_game();

    return 0;
}