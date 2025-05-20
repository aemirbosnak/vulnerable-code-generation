//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

void percol_sim(int **arr, int n, int m)
{
    int i, j, k, rand_num;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    for (k = 0; k < MAX_SIZE; k++)
    {
        rand_num = rand() % MAX_SIZE;
        arr[rand_num][rand_num] = 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
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

    percol_sim(arr, n, m);

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}