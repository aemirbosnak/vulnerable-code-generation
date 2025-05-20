//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int **ans = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        ans[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < m; l++)
                {
                    if (k != i || l != j)
                    {
                        sum += arr[k][l];
                    }
                }
            }
            ans[i][j] = sum;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}