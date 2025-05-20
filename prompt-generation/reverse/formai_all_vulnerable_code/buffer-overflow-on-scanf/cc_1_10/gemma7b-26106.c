//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, a[100], b[100], c[100], d[100], e[100];

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of points: ");
        scanf("%d", &k);

        for (j = 0; j < k; j++)
        {
            printf("Enter the x-coordinate of point %d: ", j + 1);
            scanf("%d", &a[j]);

            printf("Enter the y-coordinate of point %d: ", j + 1);
            scanf("%d", &b[j]);
        }

        l = 0;
        m = 0;

        for (j = 0; j < k; j++)
        {
            for (k = j + 1; k < k; k++)
            {
                c[l] = (a[j] - a[k]) * (b[j] - b[k]) - (a[j] - a[k]) * (b[j] - b[k]);
                l++;
            }
        }

        for (j = 0; j < l; j++)
        {
            d[j] = abs(c[j]) / 2;
        }

        e[0] = d[0];
        for (j = 1; j < l; j++)
        {
            e[j] = e[j - 1] + d[j];
        }

        printf("The total distance is: ");
        printf("%d", e[l - 1]);
        printf("\n");
    }

    return 0;
}