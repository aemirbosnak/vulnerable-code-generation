//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

int main()
{
    int i, j, k, size, **arr, **perm;

    size = MAX_SIZE;
    arr = (int *)malloc(size * size * sizeof(int));
    perm = (int *)malloc(size * size * sizeof(int));

    srand(time(NULL));

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            arr[i][j] = rand() % 2;
            perm[i][j] = -1;
        }
    }

    for (k = 0; k < 10; k++)
    {
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (arr[i][j] == 1 && perm[i][j] == -1)
                {
                    perm[i][j] = k;
                    if (i > 0 && arr[i - 1][j] == 1)
                        perm[i - 1][j] = k;
                    if (j > 0 && arr[i][j - 1] == 1)
                        perm[i][j - 1] = k;
                    if (i < size - 1 && arr[i + 1][j] == 1)
                        perm[i + 1][j] = k;
                    if (j < size - 1 && arr[i][j + 1] == 1)
                        perm[i][j + 1] = k;
                }
            }
        }
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", perm[i][j]);
        }
        printf("\n");
    }

    free(arr);
    free(perm);

    return 0;
}