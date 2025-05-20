//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

void scale_array(int **arr, int n)
{
    int i, j, k;
    int **new_arr = NULL;

    new_arr = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        new_arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            arr[i][j] = new_arr[i][j];
        }
    }

    free(new_arr);
}

int main()
{
    int n, i, j, k;
    int **arr = NULL;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &k);

    arr = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(k * sizeof(int));
    }

    scale_array(arr, n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < k; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}