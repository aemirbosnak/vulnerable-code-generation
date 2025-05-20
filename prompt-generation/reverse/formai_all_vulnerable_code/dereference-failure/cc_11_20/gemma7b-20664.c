//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j, k, l, t = 0;
    scanf("Enter the number of test cases:", &t);

    for (k = 0; k < t; k++)
    {
        scanf("Enter the number of rows and columns:", &n);
        scanf("Enter the number of operations:", &m);

        int **arr = (int **)malloc(n * sizeof(int *));
        for (i = 0; i < n; i++)
            arr[i] = (int *)malloc(m * sizeof(int));

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                scanf("Enter the element at (%d, %d):", &arr[i][j]);
            }
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                int sum = 0;
                for (l = 0; l < n; l++)
                {
                    for (k = 0; k < m; k++)
                    {
                        if (l != j && k != i)
                            sum += arr[l][k];
                    }
                }
                arr[j][i] = sum;
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                printf("The element at (%d, %d) is: %d\n", i, j, arr[i][j]);
            }
        }

        free(arr);
    }

    return 0;
}