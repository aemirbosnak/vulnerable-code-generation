//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

int main()
{
    int **board = NULL;
    int rows, cols;
    int i, j, k, l, t, alive = 0;

    // Allocate memory for the board
    board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for(i = 0; i < MAX_SIZE; i++)
    {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    rows = cols = 10;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            board[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Create random patterns
    for(t = 0; t < 10; t++)
    {
        alive = rand() % 2;
        i = rand() % rows;
        j = rand() % cols;
        board[i][j] = alive;
    }

    // Print the board
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Calculate the next generation
    for(k = 0; k < rows; k++)
    {
        for(l = 0; l < cols; l++)
        {
            int neighbors = 0;
            for(i = -1; i <= 1; i++)
            {
                for(j = -1; j <= 1; j++)
                {
                    if(board[k + i][l + j] == 1)
                    {
                        neighbors++;
                    }
                }
            }

            if(board[k][l] == 1 && neighbors < 2)
            {
                board[k][l] = 0;
            }
            else if(board[k][l] == 0 && neighbors == 3)
            {
                board[k][l] = 1;
            }
        }
    }

    // Print the next generation
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}