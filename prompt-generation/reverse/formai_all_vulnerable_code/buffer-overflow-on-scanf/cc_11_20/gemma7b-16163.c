//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>

int main()
{
    int board[20][20] = {{0}};
    int i, j, k, l, n, m;

    printf("Enter the number of generations: ");
    scanf("%d", &n);

    printf("Enter the size of the board: ");
    scanf("%d", &m);
    printf("%d", m);

    printf("Enter the initial state of the board (0 for dead, 1 for alive): ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
            {
                l = 0;
                if (i - 1 >= 0) l++;
                if (i + 1 < m) l++;
                if (j - 1 >= 0) l++;
                if (j + 1 < m) l++;

                if (board[i][j] == 1 && l < 2) board[i][j] = 0;
                else if (board[i][j] == 0 && l == 2) board[i][j] = 1;
            }
        }
    }

    printf("The final state of the board: ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}