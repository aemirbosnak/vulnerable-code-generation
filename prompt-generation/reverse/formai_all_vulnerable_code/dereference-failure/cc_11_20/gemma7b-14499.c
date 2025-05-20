//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, i, j, k, l, d;
    float x, y, z, **a, **b, **c;

    printf("Enter the number of clusters:");
    scanf("%d", &n);

    a = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++)
        a[i] = (float *)malloc(10 * sizeof(float));

    b = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++)
        b[i] = (float *)malloc(10 * sizeof(float));

    c = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++)
        c[i] = (float *)malloc(10 * sizeof(float));

    printf("Enter the number of points:");
    scanf("%d", &l);

    for (i = 0; i < l; i++)
    {
        printf("Enter the coordinates of point %d:", i + 1);
        scanf("%f %f", &x, &y);
        a[i][0] = x;
        a[i][1] = y;
    }

    for (k = 0; k < n; k++)
    {
        for (j = 0; j < l; j++)
        {
            d = 0;
            for (i = 0; i < 2; i++)
            {
                z = a[j][i] - a[k][i];
                d += z * z;
            }
            c[k][j] = d;
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("The center of cluster %d is:", i + 1);
        for (j = 0; j < 2; j++)
            printf(" (%f, %f)", b[i][j], c[i][j]);
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return;
}