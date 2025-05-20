//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int board_size = 10;
    int **board = (int **)malloc(board_size * sizeof(int *));
    for(int i = 0; i < board_size; i++)
    {
        board[i] = (int *)malloc(board_size * sizeof(int));
    }

    // Initialize the board
    for(int i = 0; i < board_size; i++)
    {
        for(int j = 0; j < board_size; j++)
        {
            board[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create a random pattern
    for(int i = 0; i < board_size; i++)
    {
        for(int j = 0; j < board_size; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    // Simulate life
    int generations = 0;
    while( generations < 10)
    {
        // Calculate the number of neighbors for each cell
        for(int i = 0; i < board_size; i++)
        {
            for(int j = 0; j < board_size; j++)
            {
                int neighbors = 0;
                // Check the cells to the north, south, east, and west
                if(i > 0) neighbors++;
                if(i < board_size - 1) neighbors++;
                if(j > 0) neighbors++;
                if(j < board_size - 1) neighbors++;

                // Apply the Game of Life rules
                if(board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
                if(board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
            }
        }

        // Increment the number of generations
        generations++;
    }

    // Print the final board
    for(int i = 0; i < board_size; i++)
    {
        for(int j = 0; j < board_size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(int i = 0; i < board_size; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}