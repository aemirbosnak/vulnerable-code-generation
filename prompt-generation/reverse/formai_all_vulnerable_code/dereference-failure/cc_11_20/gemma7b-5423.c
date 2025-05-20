//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void drawBoard(int **board)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            printf("%c ", board[r][c] ? '#' : '.');
        }
        printf("\n");
    }
}

int main()
{
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int r = 0; r < MAX_SIZE; r++)
    {
        board[r] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            board[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create a random pattern
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            board[r][c] = rand() % 2;
        }
    }

    // Draw the board
    drawBoard(board);

    // Simulate the game of life
    for (int t = 0; t < 10; t++)
    {
        // Calculate the next generation
        for (int r = 0; r < MAX_SIZE; r++)
        {
            for (int c = 0; c < MAX_SIZE; c++)
            {
                int neighbors = 0;
                for (int dr = -1; dr <= 1; dr++)
                {
                    for (int dc = -1; dc <= 1; dc++)
                    {
                        if (board[r + dr][c + dc] && board[r + dr][c + dc] != 0)
                        {
                            neighbors++;
                        }
                    }
                }

                if (board[r][c] == 0 && neighbors == 3)
                {
                    board[r][c] = 1;
                }
                else if (board[r][c] == 1 && (neighbors < 2 || neighbors > 3))
                {
                    board[r][c] = 0;
                }
            }
        }

        // Draw the board
        drawBoard(board);
    }

    // Free the memory
    for (int r = 0; r < MAX_SIZE; r++)
    {
        free(board[r]);
    }
    free(board);

    return 0;
}