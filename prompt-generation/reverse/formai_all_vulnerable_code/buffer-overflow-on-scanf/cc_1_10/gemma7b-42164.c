//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int i, j, k, l, m, n, a[MAX], b[MAX], c[MAX], d[MAX];

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the coefficients of the variables: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the constants of the equation: ");
    scanf("%d", &b[0]);

    for (i = 0; i < n; i++)
    {
        c[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                c[i] += a[i] * a[j];
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        d[i] = b[0] - c[i];
    }

    printf("The solutions to the equation are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", d[i]);
    }

    printf("\n");

    return 0;
}