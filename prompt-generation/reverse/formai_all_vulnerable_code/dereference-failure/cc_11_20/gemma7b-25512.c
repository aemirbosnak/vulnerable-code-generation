//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

int main()
{
    int **board = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    int generation = 0;
    while (1)
    {
        int alive = 0;
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                int neighbors = 0;
                if (board[i - 1][j] == 1) neighbors++;
                if (board[i + 1][j] == 1) neighbors++;
                if (board[i][j - 1] == 1) neighbors++;
                if (board[i][j + 1] == 1) neighbors++;

                if (board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
                if (board[i][j] == 0 && neighbors == 2) board[i][j] = 1;
            }
        }

        generation++;
        if (alive == 0) break;
    }

    printf("Generations: %d\n", generation);

    for (int i = 0; i < MAX; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}