//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int x, y, z, i, j, k;
    int **a = NULL;

    a = (int**)malloc(10 * sizeof(int*));
    for (x = 0; x < 10; x++)
    {
        a[x] = (int*)malloc(10 * sizeof(int));
        for (y = 0; y < 10; y++)
        {
            a[x][y] = 0;
        }
    }

    a[5][5] = 1;
    a[5][6] = 1;
    a[6][5] = 1;
    a[6][6] = 1;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            z = 0;
            if (i > 0) z += a[i - 1][j];
            if (i < 9) z += a[i + 1][j];
            if (j > 0) z += a[i][j - 1];
            if (j < 9) z += a[i][j + 1];

            if (z == 3) a[i][j] = 1;
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (x = 0; x < 10; x++)
    {
        free(a[x]);
    }
    free(a);

    return 0;
}