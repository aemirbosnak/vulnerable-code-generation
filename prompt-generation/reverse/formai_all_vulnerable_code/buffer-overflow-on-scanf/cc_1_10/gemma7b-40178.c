//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, m, i, j, k, l, r, t, x, y, z;
    scanf("%d", &t);

    for (k = 0; k < t; k++)
    {
        scanf("%d", &n);
        scanf("%d", &m);

        int **arr = (int **)malloc(n * sizeof(int *));
        for (i = 0; i < n; i++)
        {
            arr[i] = (int *)malloc(m * sizeof(int));
            for (j = 0; j < m; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        int **ans = (int **)malloc(n * sizeof(int *));
        for (i = 0; i < n; i++)
        {
            ans[i] = (int *)malloc(m * sizeof(int));
            for (j = 0; j < m; j++)
            {
                ans[i][j] = 0;
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                int max = 0;
                for (l = 0; l < n; l++)
                {
                    for (r = 0; r < m; r++)
                    {
                        if (l != i || r != j)
                        {
                            int dist = abs(l - i) + abs(r - j);
                            if (dist > max)
                            {
                                max = dist;
                            }
                        }
                    }
                }
                ans[i][j] = max;
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }

        free(arr);
        free(ans);
    }

    return 0;
}