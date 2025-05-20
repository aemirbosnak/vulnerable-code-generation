//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void percolat(int **arr, int n, int m)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                int x = i;
                int y = j;

                // Traverse the four directions
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m && arr[x + dx][y + dy] == 1)
                        {
                            arr[x + dx][y + dy] = 2;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    percolat(arr, n, m);

    return 0;
}