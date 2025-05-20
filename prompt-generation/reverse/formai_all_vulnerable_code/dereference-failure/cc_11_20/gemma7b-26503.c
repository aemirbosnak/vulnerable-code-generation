//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>
#include <stdlib.h>

void GameOfLife(int **board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int neighbors = 0;
            // Check the 8 neighbors
            if (i > 0) neighbors++;
            if (i < size - 1) neighbors++;
            if (j > 0) neighbors++;
            if (j < size - 1) neighbors++;
            if (i > 0 && j > 0) neighbors++;
            if (i > 0 && j < size - 1) neighbors++;
            if (i < size - 1 && j > 0) neighbors++;
            if (i < size - 1 && j < size - 1) neighbors++;

            // Apply the rules
            if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
            if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) board[i][j] = 0;
        }
    }
}

int main()
{
    int size = 5;
    int **board = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) board[i] = (int *)malloc(size * sizeof(int));

    // Initialize the board
    board[1][1] = 1;
    board[2][2] = 1;
    board[2][3] = 1;

    // Play the game for 10 generations
    for (int gen = 0; gen < 10; gen++)
    {
        GameOfLife(board, size);
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

    return 0;
}