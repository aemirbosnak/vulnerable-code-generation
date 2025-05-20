//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, i, j, n, k, l, m, b[10][10] = {{0}};

    printf("Enter the number of generations:");
    scanf("%d", &n);

    for (k = 0; k < n; k++)
    {
        printf("Generation %d:\n", k + 1);

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                b[i][j] = 0;
            }
        }

        printf("Enter the number of living cells:");
        scanf("%d", &l);

        for (i = 0; i < l; i++)
        {
            printf("Enter the coordinates of the living cell:");
            scanf("%d %d", &x, &y);

            b[x][y] = 1;
        }

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                m = 0;

                if (i - 1 >= 0)
                    m++;
                if (i + 1 < 10)
                    m++;
                if (j - 1 >= 0)
                    m++;
                if (j + 1 < 10)
                    m++;

                if (b[i][j] == 1 && m < 2)
                    b[i][j] = 0;
                else if (b[i][j] == 0 && m == 3)
                    b[i][j] = 1;
            }
        }

        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                printf("%d ", b[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}