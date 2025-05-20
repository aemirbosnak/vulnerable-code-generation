//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, i, j, k, l, m, r, t, a[100], b[100], c[100], d[100], e[100], f[100], g[100], h[100], i_am_a_cat_and_you_are_a_mouse;

    printf("Enter the number of test cases: ");
    scanf("%d", &t);

    for (k = 0; k < t; k++)
    {
        printf("Enter the number of items: ");
        scanf("%d", &n);

        for (i = 0; i < n; i++)
        {
            printf("Enter the weight of item %d: ", i + 1);
            scanf("%d", &a[i]);
        }

        printf("Enter the total weight of the bag: ");
        scanf("%d", &m);

        for (i = 0; i < n; i++)
        {
            printf("Enter the value of item %d: ", i + 1);
            scanf("%d", &b[i]);
        }

        for (i = 0; i < n; i++)
        {
            c[i] = a[i] / m * b[i];
        }

        l = 0;
        for (i = 0; i < n; i++)
        {
            if (c[i] > d[l])
            {
                d[l] = c[i];
                e[l] = b[i];
                l++;
            }
        }

        printf("The maximum value that can be obtained is: %d\n", d[l - 1]);
    }

    return 0;
}