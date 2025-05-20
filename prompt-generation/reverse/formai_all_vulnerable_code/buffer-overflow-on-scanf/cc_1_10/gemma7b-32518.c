//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void initialize(int **arr, int n);
void display(int **arr, int n);

int main()
{
    int **arr;
    int n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    initialize(arr, n);
    display(arr, n);

    free(arr);

    return 0;
}

void initialize(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void display(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}