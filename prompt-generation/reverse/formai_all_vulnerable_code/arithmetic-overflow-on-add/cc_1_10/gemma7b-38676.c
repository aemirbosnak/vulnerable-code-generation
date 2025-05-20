//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Matrix_Operations(int **a, int **b, int **c, int n)
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int n = 3;
    int **a = (int **)malloc(n * sizeof(int *));
    int **b = (int **)malloc(n * sizeof(int *));
    int **c = (int **)malloc(n * sizeof(int *));

    a[0] = (int *)malloc(n * sizeof(int));
    a[1] = (int *)malloc(n * sizeof(int));
    a[2] = (int *)malloc(n * sizeof(int));

    b[0] = (int *)malloc(n * sizeof(int));
    b[1] = (int *)malloc(n * sizeof(int));
    b[2] = (int *)malloc(n * sizeof(int));

    c[0] = (int *)malloc(n * sizeof(int));
    c[1] = (int *)malloc(n * sizeof(int));
    c[2] = (int *)malloc(n * sizeof(int));

    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;

    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;

    a[2][0] = 7;
    a[2][1] = 8;
    a[2][2] = 9;

    b[0][0] = 10;
    b[0][1] = 11;
    b[0][2] = 12;

    b[1][0] = 13;
    b[1][1] = 14;
    b[1][2] = 15;

    b[2][0] = 16;
    b[2][1] = 17;
    b[2][2] = 18;

    Matrix_Operations(a, b, c, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    free(a);
    free(b);
    free(c);

    return 0;
}