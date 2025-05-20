//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void shift_memory(int **arr, int n)
{
    int i, j, k;
    for (i = n - 1; i >= 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            k = arr[j][i] - arr[j][i - 1];
            arr[j][i] = arr[j][i - 1] - k;
        }
    }
}

int main()
{
    int **arr = NULL;
    int n, i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &i);

    arr = (int **)malloc(n * sizeof(int *));
    for (j = 0; j < n; j++)
    {
        arr[j] = (int *)malloc(i * sizeof(int));
    }

    printf("Enter the elements of the matrix: ");
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < i; i++)
        {
            scanf("%d", &arr[j][i]);
        }
    }

    shift_memory(arr, n);

    printf("The shifted matrix is: ");
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < i; i++)
        {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}