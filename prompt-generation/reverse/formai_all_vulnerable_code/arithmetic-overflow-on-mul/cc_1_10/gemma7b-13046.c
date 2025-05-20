//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

void percolatesim(int **arr, int n)
{
    int i, j, k, r, c;
    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    for (r = 0; r < MAX_SIZE; r++)
    {
        for (c = 0; c < MAX_SIZE; c++)
        {
            if (arr[r][c] == 1)
            {
                k = rand() % 4;
                switch (k)
                {
                    case 0:
                        arr[r - 1][c] = 1;
                        break;
                    case 1:
                        arr[r + 1][c] = 1;
                        break;
                    case 2:
                        arr[r][c - 1] = 1;
                        break;
                    case 3:
                        arr[r][c + 1] = 1;
                        break;
                }
            }
        }
    }
}

int main()
{
    int n, i, j;
    int **arr;

    printf("Enter the size of the grid: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    percolatesim(arr, n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}