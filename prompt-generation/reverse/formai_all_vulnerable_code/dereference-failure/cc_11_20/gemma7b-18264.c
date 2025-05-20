//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    int **board = malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        board[i] = malloc(10 * sizeof(int));
    }

    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            board[x][y] = rand() % 2;
        }
    }

    int generations = 0;
    while (1)
    {
        system("clear");
        for (int x = 0; x < 10; x++)
        {
            for (int y = 0; y < 10; y++)
            {
                int neighbors = 0;
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        if (x + dx >= 0 && x + dx < 10 && y + dy >= 0 && y + dy < 10)
                        {
                            neighbors += board[x + dx][y + dy];
                        }
                    }
                }

                if (board[x][y] == 0 && neighbors >= 3)
                {
                    board[x][y] = 1;
                }
                else if (board[x][y] == 1 && neighbors < 2)
                {
                    board[x][y] = 0;
                }
            }
        }

         generations++;
        printf("Generation %d:\n", generations);
        for (int x = 0; x < 10; x++)
        {
            for (int y = 0; y < 10; y++)
            {
                printf("%d ", board[x][y]);
            }
            printf("\n");
        }

        if ( generations >= 10)
        {
            break;
        }
    }

    free(board);

    return 0;
}