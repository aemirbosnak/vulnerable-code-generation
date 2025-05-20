//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a 2D array to store the game board
    int board[5][5] = {{0, 0, 0, 0, 0},
                              {0, 1, 1, 0, 0},
                              {0, 1, 1, 0, 0},
                              {0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0}};

    // Simulate the post-apocalyptic environment
    board[2][2] = 1; // Survivor

    // Play the Game of Life
    for (int i = 0; i < 10; i++)
    {
        // Calculate the next generation of the game board
        int next_board[5][5] = {{0, 0, 0, 0, 0},
                                {0, 1, 1, 0, 0},
                                {0, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}};

        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                int num_neighbors = 0;
                // Check the number of neighbors for each cell
                if (board[r-1][c] == 1) num_neighbors++;
                if (board[r+1][c] == 1) num_neighbors++;
                if (board[r][c-1] == 1) num_neighbors++;
                if (board[r][c+1] == 1) num_neighbors++;

                // Apply the Game of Life rules
                if (board[r][c] == 1 && num_neighbors < 2) next_board[r][c] = 0;
                if (board[r][c] == 0 && num_neighbors == 3) next_board[r][c] = 1;
            }
        }

        // Copy the next generation board to the current board
        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                board[r][c] = next_board[r][c];
            }
        }
    }

    // Print the final game board
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