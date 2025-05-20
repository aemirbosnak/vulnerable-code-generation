//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100], f[100], g[100], h[100], i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, x, y, z;

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of items: ");
        scanf("%d", &m);

        printf("Enter the weights of each item: ");
        for (j = 0; j < m; j++)
            scanf("%d", &a[j]);

        printf("Enter the total weight: ");
        scanf("%d", &x);

        i1 = 0;
        i2 = 0;
        i3 = 0;
        i4 = 0;
        i5 = 0;
        i6 = 0;
        i7 = 0;
        i8 = 0;
        i9 = 0;
        i10 = 0;

        for (j = 0; j < m; j++)
        {
            for (k = 0; k < x; k++)
            {
                if (a[j] <= k)
                {
                    i1++;
                }
                if (a[j] <= k * 2)
                {
                    i2++;
                }
                if (a[j] <= k * 3)
                {
                    i3++;
                }
                if (a[j] <= k * 4)
                {
                    i4++;
                }
                if (a[j] <= k * 5)
                {
                    i5++;
                }
                if (a[j] <= k * 6)
                {
                    i6++;
                }
                if (a[j] <= k * 7)
                {
                    i7++;
                }
                if (a[j] <= k * 8)
                {
                    i8++;
                }
                if (a[j] <= k * 9)
                {
                    i9++;
                }
                if (a[j] <= k * 10)
                {
                    i10++;
                }
            }
        }

        printf("The number of items that can be placed in the bag is: %d", i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10);
    }

    return 0;
}