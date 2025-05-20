//Gemma-7B DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    int i, j, k, n, m;
    int **arr = NULL;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    printf("Enter the elements of the matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The elements of the matrix are: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
    }

    printf("\nThe sum of the elements of the matrix is: ");
    k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            k += arr[i][j];
        }
    }
    printf("%d", k);

    return 0;
}