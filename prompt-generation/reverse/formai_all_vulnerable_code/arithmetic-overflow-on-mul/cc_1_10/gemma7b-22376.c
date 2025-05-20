//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

int main()
{
    int a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
    int i, j, k, n, m, l;

    printf("Enter the dimensions of the matrices (n, m, l): ");
    scanf("%d %d %d", &n, &m, &l);

    printf("Enter the elements of the first matrix (a): ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d ", &a[i * m + j]);
        }
    }

    printf("Enter the elements of the second matrix (b): ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d ", &b[i * m + j]);
        }
    }

    k = l;
    l = m * n;
    m = n;
    n = m * k;

    for (i = 0; i < n; i++)
    {
        c[i] = 0;
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < k; k++)
            {
                c[i] += a[j * m + k] * b[k];
            }
        }
    }

    printf("The product of the two matrices (c) is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", c[i * m + j]);
        }
        printf("\n");
    }

    return 0;
}