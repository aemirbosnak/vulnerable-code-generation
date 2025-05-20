//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int main()
{
    int i, j, n, m, a[MAX], b[MAX], c[MAX], d[MAX], e[MAX];
    double avg, sum, total = 0, p, q, r, s, t, u, v, w, x, y, z;

    printf("Enter the number of stocks: ");
    scanf("%d", &n);

    printf("Enter the stock prices: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the number of days: ");
    scanf("%d", &m);

    printf("Enter the daily price changes: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    for (i = 0; i < n; i++)
    {
        c[i] = a[i] + b[i];
    }

    for (i = 0; i < n; i++)
    {
        d[i] = c[i] - a[i];
    }

    for (i = 0; i < n; i++)
    {
        e[i] = d[i] / a[i] * 100;
    }

    avg = (sum / n) * 100;
    total = 0;

    for (i = 0; i < n; i++)
    {
        total += e[i];
    }

    printf("The average return is: %.2lf%%", avg);
    printf("\nThe total return is: %.2lf%%", total);

    return 0;
}