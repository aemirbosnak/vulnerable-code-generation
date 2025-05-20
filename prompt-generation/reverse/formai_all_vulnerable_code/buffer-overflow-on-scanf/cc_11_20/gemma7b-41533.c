//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

int main()
{
    int n, m, i, j, k, l, r, x, y, z;
    scanf("%d", &n);
    scanf("%d", &m);

    int **a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(m * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    x = 0;
    y = 0;
    z = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
            {
                x++;
                l = i;
                r = j;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == 2)
            {
                y++;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == 3)
            {
                z++;
            }
        }
    }

    printf("The number of 1s is: %d\n", x);
    printf("The number of 2s is: %d\n", y);
    printf("The number of 3s is: %d\n", z);

    printf("The location of the first 1 is: (%d, %d)\n", l, r);

    free(a);

    return 0;
}