//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

void GameOfLife(int **board, int n)
{
    int i, j, k, l, count, alive = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            count = 0;
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (k == 0 && l == 0)
                        continue;
                    if (board[i + k][j + l] == 1)
                        count++;
                }
            }
            if (board[i][j] == 1 && count < 2)
                alive++;
            else if (board[i][j] == 0 && count == 3)
                alive++;
        }
    }
    printf("The number of alive cells is: %d\n", alive);
}

int main()
{
    int n;
    printf("Enter the size of the grid: ");
    scanf("%d", &n);

    int **board = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        board[i] = (int *)malloc(n * sizeof(int));

    printf("Enter the initial state of the grid (0 for dead, 1 for alive):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d ", &board[i][j]);
        }
    }

    GameOfLife(board, n);

    return 0;
}