//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reshape(int **arr, int n, int m)
{
    int i, j, k;
    int **new_arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        new_arr[i] = (int *)malloc(m * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            new_arr[i][j] = arr[i][j];
        }
    }
    free(arr);
    arr = new_arr;
}

int main()
{
    int **arr = NULL;
    int n = 0, m = 0;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    printf("Enter number of columns: ");
    scanf("%d", &m);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter elements of the matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Reshaped matrix: ");
    reshape(arr, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}