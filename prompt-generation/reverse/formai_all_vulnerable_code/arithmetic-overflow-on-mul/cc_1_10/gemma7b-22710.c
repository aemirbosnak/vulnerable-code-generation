//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void percolat(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                arr[i][j] = 2;
                if (i > 0)
                    arr[i - 1][j] = 2;
                if (j > 0)
                    arr[i][j - 1] = 2;
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("Enter the number of rows: ", &n);
    scanf("Enter the number of columns: ", &m);

    int **arr = (int *)malloc(n * m * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("Enter the state of the cell (0/1): ", &arr[i][j]);
        }
    }

    percolat(arr, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("The state of the cell is: %d\n", arr[i][j]);
        }
    }

    free(arr);

    return 0;
}