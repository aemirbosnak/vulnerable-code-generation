//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k, l, n = 10;
    char b[20], c[20], d[20], e[20], f[20], g[20];
    double a[n], m, o, p, q, r, s, t, u, v, w, x, y, z;
    time_t t1, t2, t3, t4;

    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the name of the stock: ");
        scanf("%s", b);

        printf("Enter the current price of the stock: ");
        scanf("%lf", &a[i]);

        printf("Enter the 5-day moving average of the stock: ");
        scanf("%lf", &m);

        printf("Enter the 20-day moving average of the stock: ");
        scanf("%lf", &o);

        printf("Enter the support level of the stock: ");
        scanf("%lf", &p);

        printf("Enter the resistance level of the stock: ");
        scanf("%lf", &q);
    }

    t1 = time(NULL);
    t2 = t1 + 3600;
    t3 = t2 + 3600;
    t4 = t3 + 3600;

    for (j = 0; j < 4; j++)
    {
        for (k = 0; k < n; k++)
        {
            r = a[k] + (m - a[k]) / 2;
            s = a[k] - (o - a[k]) / 2;
            t = p - (a[k] - r) / 2;
            u = q + (a[k] - r) / 2;

            printf("%s: %.2lf, %.2lf, %.2lf, %.2lf, %.2lf\n", b[k], a[k], r, s, t, u);
        }

        printf("\n");
    }

    t4 = time(NULL) - t1;
    printf("Total time taken: %.2lf seconds\n", t4);

    return 0;
}