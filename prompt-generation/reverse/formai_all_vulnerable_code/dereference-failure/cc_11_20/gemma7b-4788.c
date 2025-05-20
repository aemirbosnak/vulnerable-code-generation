//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

int main()
{
    int **board = (int **)malloc(HEIGHT * sizeof(int *));
    for(int r = 0; r < HEIGHT; r++)
    {
        board[r] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Initialize the board
    for(int r = 0; r < HEIGHT; r++)
    {
        for(int c = 0; c < WIDTH; c++)
        {
            board[r][c] = 0;
        }
    }

    // Game loop
    int generation = 0;
    while(1)
    {
        // Print the board
        for(int r = 0; r < HEIGHT; r++)
        {
            for(int c = 0; c < WIDTH; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Calculate the next generation
        for(int r = 0; r < HEIGHT; r++)
        {
            for(int c = 0; c < WIDTH; c++)
            {
                int neighbors = 0;
                // Check the neighbors
                if(board[r-1][c] == 1) neighbors++;
                if(board[r+1][c] == 1) neighbors++;
                if(board[r][c-1] == 1) neighbors++;
                if(board[r][c+1] == 1) neighbors++;

                // Apply the rules
                if(board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
                if(board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
            }
        }

        // Increment the generation
        generation++;

        // Check if the game is over
        if(generation > 10) break;
    }

    // Free the memory
    for(int r = 0; r < HEIGHT; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}