//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main()
{
    int i, j, k, l, **a, **b;
    a = (int *)malloc(MAX * MAX * sizeof(int));
    b = (int *)malloc(MAX * MAX * sizeof(int));

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            a[i][j] = rand() % 2;
            b[i][j] = 0;
        }
    }

    for (k = 0; k < 10; k++)
    {
        for (l = 0; l < MAX; l++)
        {
            for (i = 0; i < MAX; i++)
            {
                for (j = 0; j < MAX; j++)
                {
                    int n = 0;
                    if (a[i - 1][j] == 1) n++;
                    if (a[i + 1][j] == 1) n++;
                    if (a[i][j - 1] == 1) n++;
                    if (a[i][j + 1] == 1) n++;

                    if (a[i][j] == 1 && n < 2) b[i][j] = 0;
                    if (a[i][j] == 0 && n == 3) b[i][j] = 1;
                }
            }
        }
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);

    return 0;
}