//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main()
{
    int **arr = NULL;
    int i, j, k, n, m, seed;

    printf("Enter number of iterations: ");
    scanf("%d", &n);

    printf("Enter seed: ");
    scanf("%d", &seed);

    srand(seed);

    arr = (int *)malloc(N * N * sizeof(int));

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (arr[i][j] == 1)
                {
                    int r = rand() % 4;
                    switch (r)
                    {
                        case 0:
                            arr[i - 1][j] = 1;
                            break;
                        case 1:
                            arr[i + 1][j] = 1;
                            break;
                        case 2:
                            arr[i][j - 1] = 1;
                            break;
                        case 3:
                            arr[i][j + 1] = 1;
                            break;
                    }
                }
            }
        }
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}