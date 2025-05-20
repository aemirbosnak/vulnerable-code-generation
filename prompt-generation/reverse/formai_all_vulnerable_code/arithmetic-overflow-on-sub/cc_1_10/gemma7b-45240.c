//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void search(int **arr, int n, int target)
{
    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
        int mid = (i + j) / 2;

        if (arr[mid] == target)
        {
            printf("Target found at index %d\n", mid);
            return;
        }
        else if (arr[mid] < target)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }

    printf("Target not found\n");
}

int main()
{
    int n;
    int target;

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

    printf("Enter the target: ");
    scanf("%d", &target);

    search(arr, n, target);

    return 0;
}