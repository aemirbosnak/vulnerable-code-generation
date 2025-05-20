//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int **board = (int **)malloc(MAX * sizeof(int *)), i, j;

    for (i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    // Game rules
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            board[i][j] = 0;
        }
    }

    board[4][4] = 1;
    board[5][4] = 1;
    board[5][5] = 1;
    board[4][5] = 1;

    // Simulation
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            int neighbors = 0;

            if (board[i - 1][j] == 1) neighbors++;
            if (board[i + 1][j] == 1) neighbors++;
            if (board[i][j - 1] == 1) neighbors++;
            if (board[i][j + 1] == 1) neighbors++;

            if (board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
            else if (board[i][j] == 0 && neighbors == 3) board[i][j] = 1;
        }
    }

    // Output
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    free(board);
    return 0;
}