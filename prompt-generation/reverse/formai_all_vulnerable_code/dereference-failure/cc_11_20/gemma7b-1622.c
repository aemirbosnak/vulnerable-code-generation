//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, k, l, n, m;
    char **a, **b, **c, **d, **e;

    a = (char**)malloc(10 * sizeof(char*));
    b = (char**)malloc(10 * sizeof(char*));
    c = (char**)malloc(10 * sizeof(char*));
    d = (char**)malloc(10 * sizeof(char*));
    e = (char**)malloc(10 * sizeof(char*));

    n = 10;
    m = 20;

    for (i = 0; i < n; i++)
    {
        a[i] = (char*)malloc(m * sizeof(char));
        b[i] = (char*)malloc(m * sizeof(char));
        c[i] = (char*)malloc(m * sizeof(char));
        d[i] = (char*)malloc(m * sizeof(char));
        e[i] = (char*)malloc(m * sizeof(char));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            a[i][j] = rand() % 256;
            b[i][j] = rand() % 256;
            c[i][j] = rand() % 256;
            d[i][j] = rand() % 256;
            e[i][j] = rand() % 256;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < 5; k++)
            {
                l = rand() % 2;
                c[i][j] ^= l;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%x ", c[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            free(a[i]);
            free(b[i]);
            free(c[i]);
            free(d[i]);
            free(e[i]);
        }
        free(a[i]);
    }

    return 0;
}