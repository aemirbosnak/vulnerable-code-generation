//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int main()
{
    int **board = NULL;
    int size = 0;

    // Allocate memory for the board
    board = malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    size = 5;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = 0;
        }
    }

    // Set some cells to 1
    board[2][2] = 1;
    board[3][2] = 1;
    board[3][3] = 1;

    // Simulate the Game of Life
    for (int t = 0; t < 10; t++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int neighbors = 0;
                // Check the neighbors
                if (board[i-1][j] == 1) neighbors++;
                if (board[i+1][j] == 1) neighbors++;
                if (board[i][j-1] == 1) neighbors++;
                if (board[i][j+1] == 1) neighbors++;

                // Apply the Game of Life rules
                if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
                if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) board[i][j] = 0;
            }
        }
    }

    // Print the final board
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}