//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main()
{
    int **board = NULL;
    int i, j, k, l, r, c, x, y;

    board = (int **)malloc(MAX * sizeof(int *));
    for (i = 0; i < MAX; i++)
    {
        board[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            board[i][j] = 0;
        }
    }

    board[10][10] = 1;
    board[10][11] = 1;
    board[11][10] = 1;
    board[11][11] = 1;

    c = 0;
    while (c < 10)
    {
        for (i = 0; i < MAX; i++)
        {
            for (j = 0; j < MAX; j++)
            {
                x = i - 1;
                y = j - 1;

                if (x < 0)
                    x = 0;
                if (y < 0)
                    y = 0;

                l = 0;
                r = 0;
                for (k = x; k <= x + 1; k++)
                {
                    for (l = y; l <= y + 1; l++)
                    {
                        if (board[k][l] == 1)
                            r++;
                    }
                }

                if (board[i][j] == 0 && r == 3)
                    board[i][j] = 1;
                else if (board[i][j] == 1 && (r < 2 || r > 3))
                    board[i][j] = 0;
            }
        }

        c++;
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}