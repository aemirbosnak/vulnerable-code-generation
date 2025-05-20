//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a 2D array to store the game board
    int board[5][5] = {{0, 0, 0, 0, 0},
                           {0, 1, 1, 0, 0},
                           {0, 1, 1, 1, 0},
                           {0, 0, 0, 1, 0},
                           {0, 0, 0, 0, 0}};

    // Define the number of neighbors a cell has to survive
    int survive_neighbors = 3;

    // Iterate over the game board and apply the Game of Life rules
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            // Calculate the number of neighbors a cell has
            int num_neighbors = 0;
            for (int dr = -1; dr <= 1; dr++)
            {
                for (int dc = -1; dc <= 1; dc++)
                {
                    // Check if the neighbor cell is alive and not the current cell
                    if (board[r + dr][c + dc] && board[r + dr][c + dc] != board[r][c])
                    {
                        num_neighbors++;
                    }
                }
            }

            // Apply the Game of Life rules
            if (board[r][c] == 1 && num_neighbors < survive_neighbors)
            {
                board[r][c] = 0;
            }
            else if (board[r][c] == 0 && num_neighbors == survive_neighbors)
            {
                board[r][c] = 1;
            }
        }
    }

    // Print the updated game board
    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    return 0;
}