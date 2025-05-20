//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, l, n, m, board[10][10] = {{0}};
    printf("Enter the number of generations:");
    scanf("%d", &n);
    printf("Enter the size of the board:");
    scanf("%d", &m);
    printf("Enter the size of the neighborhood:");
    scanf("%d", &l);
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("Enter the initial state of the cell (0/1): ");
            scanf("%d", &board[i][j]);
        }
    }

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < m; j++)
            {
                int neighbors = 0;
                for(l = -l; l <= l; l++)
                {
                    for(int h = -l; h <= l; h++)
                    {
                        if(board[i + l][j + h] == 1)
                        {
                            neighbors++;
                        }
                    }
                }
                if(board[i][j] == 1 && neighbors < 2)
                {
                    board[i][j] = 0;
                }
                else if(board[i][j] == 0 && neighbors == 3)
                {
                    board[i][j] = 1;
                }
            }
        }
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}