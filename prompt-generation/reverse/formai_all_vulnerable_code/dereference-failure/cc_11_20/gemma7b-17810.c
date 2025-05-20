//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void GameOfLife(int **board, int size)
{
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            int neighbors = 0;
            // Check the 8 neighbors
            if (r > 0) neighbors++;
            if (r < size - 1) neighbors++;
            if (c > 0) neighbors++;
            if (c < size - 1) neighbors++;
            if (r > 0 && c > 0) neighbors++;
            if (r > 0 && c < size - 1) neighbors++;
            if (r < size - 1 && c > 0) neighbors++;
            if (r < size - 1 && c < size - 1) neighbors++;

            // Apply the rules
            if (board[r][c] == 1 && neighbors < 2) board[r][c] = 0;
            if (board[r][c] == 0 && neighbors == 3) board[r][c] = 1;
        }
    }
}

int main()
{
    int size = 10;
    int **board = malloc(size * size * sizeof(int));
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            board[r][c] = 0;
        }
    }

    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;

    GameOfLife(board, size);

    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    free(board);

    return 0;
}