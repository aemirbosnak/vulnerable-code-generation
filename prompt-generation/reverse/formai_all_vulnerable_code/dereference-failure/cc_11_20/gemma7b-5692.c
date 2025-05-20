//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int **board = NULL;
    int size = 0;
    int x, y;

    // Allocate memory for the board
    board = malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        board[i] = malloc(MAX_SIZE * sizeof(int));
    }

    // Initialize the board
    size = 5;
    for (x = 0; x < size; x++)
    {
        for (y = 0; y < size; y++)
        {
            board[x][y] = 0;
        }
    }

    // Set some cells to 1
    board[2][2] = 1;
    board[2][3] = 1;
    board[3][2] = 1;

    // Simulate the Game of Life
    for (int generation = 0; generation < 10; generation++)
    {
        // Calculate the number of neighbors for each cell
        for (x = 0; x < size; x++)
        {
            for (y = 0; y < size; y++)
            {
                int neighbors = 0;
                if (x > 0) neighbors++;
                if (x < size - 1) neighbors++;
                if (y > 0) neighbors++;
                if (y < size - 1) neighbors++;

                // Apply the Game of Life rules
                if (board[x][y] == 1 && neighbors < 2) board[x][y] = 0;
                if (board[x][y] == 0 && neighbors == 3) board[x][y] = 1;
            }
        }

        // Print the board
        for (x = 0; x < size; x++)
        {
            for (y = 0; y < size; y++)
            {
                printf("%d ", board[x][y]);
            }
            printf("\n");
        }
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}