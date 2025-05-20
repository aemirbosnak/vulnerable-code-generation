//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int n, i, j, k, l, r, c, a[MAX], b[MAX], d[MAX], e[MAX];

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of vertices: ");
        scanf("%d", &k);

        printf("Enter the edges: ");
        for (j = 0; j < k; j++)
        {
            scanf("%d %d", &a[j], &b[j]);
        }

        printf("Enter the queries: ");
        for (j = 0; j < k; j++)
        {
            scanf("%d %d", &c, &d[j]);
        }

        l = 0;
        r = k - 1;
        for (j = 0; j < k; j++)
        {
            e[j] = 0;
            for (i = 0; i < k; i++)
            {
                if (a[i] == c && b[i] == d[j])
                {
                    e[j] = 1;
                }
            }
        }

        for (j = 0; j < k; j++)
        {
            if (e[j] == 1)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }

    return 0;
}