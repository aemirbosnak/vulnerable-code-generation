//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: intelligent
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 100

int main()
{
    int **arr;
    int i, j, k, t, r, c;

    arr = (int *)malloc(MAX * MAX * sizeof(int));

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            arr[i][j] = 0;
        }
    }

    srand(time(NULL));

    t = rand() % MAX;
    r = rand() % MAX;
    c = rand() % MAX;

    arr[r][c] = 1;

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] == 1)
            {
                int dx[] = {1, -1, 0, 0};
                int dy[] = {0, 0, 1, -1};

                for (k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x >= 0 && x < MAX && y >= 0 && y < MAX && arr[x][y] == 0)
                    {
                        arr[x][y] = 1;
                    }
                }
            }
        }
    }

    printf("Percolation Simulation:\n");

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }

    free(arr);

    return 0;
}