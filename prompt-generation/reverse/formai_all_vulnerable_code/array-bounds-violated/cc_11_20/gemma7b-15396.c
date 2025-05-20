//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};

    int n = 10;
    int i, j, k, l, m, count = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            count = 0;
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (a[i + k][j + l] != 0)
                    {
                        count++;
                    }
                }
            }

            if (a[i][j] == 0 && count >= 3)
            {
                a[i][j] = 1;
            }
            else if (a[i][j] == 1 && count < 2)
            {
                a[i][j] = 0;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}