//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000000

int main()
{
    int n, i, j, k, l, r, t, x, y;
    long long int a[MAX], b[MAX], c[MAX], d[MAX], e[MAX];

    scanf("Enter the number of test cases: ", &t);

    for (k = 0; k < t; k++)
    {
        scanf("Enter the number of points: ", &n);

        for (i = 0; i < n; i++)
        {
            scanf("Enter the x-coordinate: ", &a[i]);
            scanf("Enter the y-coordinate: ", &b[i]);
        }

        for (i = 0; i < n; i++)
        {
            c[i] = a[i] * a[i] + b[i] * b[i];
        }

        for (i = 0; i < n; i++)
        {
            d[i] = sqrt(c[i]);
        }

        for (i = 0; i < n; i++)
        {
            e[i] = d[i] * d[i];
        }

        printf("The total distance is: ");

        for (i = 0; i < n; i++)
        {
            printf("%lld ", e[i]);
        }

        printf("\n");
    }

    return 0;
}