//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void search(int **arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == key)
            {
                printf("Key found at (%d, %d)\n", i, j);
                return;
            }
        }
    }

    printf("Key not found\n");
}

int main()
{
    int **arr = NULL;
    int n = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter the key to search for: ");
    int key = 0;
    scanf("%d", &key);

    search(arr, n, key);

    return 0;
}