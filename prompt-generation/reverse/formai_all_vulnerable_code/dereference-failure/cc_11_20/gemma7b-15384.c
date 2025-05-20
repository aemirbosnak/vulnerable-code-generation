//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main()
{
    int **board = (int **)malloc(MAX * sizeof(int *));
    for(int i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    int generations = 0;
    while(1)
    {
        for(int i = 0; i < MAX; i++)
        {
            for(int j = 0; j < MAX; j++)
            {
                int neighbors = 0;
                if(board[i-1][j] == 1) neighbors++;
                if(board[i+1][j] == 1) neighbors++;
                if(board[i][j-1] == 1) neighbors++;
                if(board[i][j+1] == 1) neighbors++;

                if(board[i][j] == 1 && neighbors < 2) board[i][j] = 0;
                else if(board[i][j] == 0 && neighbors == 2) board[i][j] = 1;
            }
        }

        generations++;
        if(generations == 10) break;

        printf("Generation %d:\n", generations);
        for(int i = 0; i < MAX; i++)
        {
            for(int j = 0; j < MAX; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}