//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;
    int **arr = (int**)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    for (int t = 0; t < 10; t++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int count = 0;
                if (i - 1 >= 0)
                {
                    count++;
                }
                if (i + 1 < n)
                {
                    count++;
                }
                if (j - 1 >= 0)
                {
                    count++;
                }
                if (j + 1 < n)
                {
                    count++;
                }

                arr[i][j] = count % 2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}