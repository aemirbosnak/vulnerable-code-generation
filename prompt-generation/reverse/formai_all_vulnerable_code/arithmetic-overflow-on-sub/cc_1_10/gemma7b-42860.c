//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void greedy_insertion(int **arr, int n)
{
    int i = 0;
    int j = 1;
    while (i < n - 1)
    {
        for (j = i + 1; j < n && arr[j] < arr[i]; j++)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        i++;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    greedy_insertion(arr, n);

    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}