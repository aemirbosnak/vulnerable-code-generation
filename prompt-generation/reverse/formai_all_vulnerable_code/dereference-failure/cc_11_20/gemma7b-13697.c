//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GENERATIONS 20
#define BOARD_SIZE 25

int main()
{
    int **board = NULL;
    int generation = 0;

    // Allocate memory for the board
    board = malloc(BOARD_SIZE * sizeof(int *));
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        board[i] = malloc(BOARD_SIZE * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create the initial pattern
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;
    board[7][5] = 1;

    // Simulate the game of life for a number of generations
    while (generation < MAX_GENERATIONS)
    {
        // Calculate the number of neighbors for each cell
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                int neighbors = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (board[i + x][j + y] == 1)
                        {
                            neighbors++;
                        }
                    }
                }

                // Apply the rules of life
                if (board[i][j] == 0 && neighbors == 3)
                {
                    board[i][j] = 1;
                }
                else if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3))
                {
                    board[i][j] = 0;
                }
            }
        }

        // Increment the generation number
        generation++;
    }

    // Print the final board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}