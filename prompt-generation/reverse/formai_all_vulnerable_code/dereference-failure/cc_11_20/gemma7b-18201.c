//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

int main()
{
    int **a = (int **)malloc(MAX * sizeof(int *));
    for (int i = 0; i < MAX; i++)
    {
        a[i] = (int *)malloc(MAX * sizeof(int));
    }

    int i, j, k, l;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            a[i][j] = rand() % 10;
        }
    }

    for (k = 0; k < MAX; k++)
    {
        for (l = 0; l < MAX; l++)
        {
            int sum = 0;
            for (i = 0; i < MAX; i++)
            {
                for (j = 0; j < MAX; j++)
                {
                    if (a[i][j] == a[k][l])
                    {
                        sum++;
                    }
                }
            }

            a[k][l] = sum;
        }
    }

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    free(a);

    return 0;
}