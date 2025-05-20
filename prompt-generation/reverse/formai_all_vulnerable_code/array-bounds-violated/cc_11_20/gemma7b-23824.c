//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a 2D array to store the game board
    int board[5][5] = {{0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 0},
                              {0, 1, 1, 1, 0},
                              {0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0}};

    // Initialize the game rules
    int rules[4] = {0, 1, 1, 1};

    // Play the game
    for (int i = 0; i < 10; i++)
    {
        // Calculate the next generation of cells
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                int neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                if (board[r][c] == 1 && neighbors < rules[0])
                {
                    board[r][c] = 0;
                }
                else if (board[r][c] == 0 && neighbors == rules[1])
                {
                    board[r][c] = 1;
                }
            }
        }

        // Print the game board
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Pause the game
        system("pause");
    }

    return 0;
}