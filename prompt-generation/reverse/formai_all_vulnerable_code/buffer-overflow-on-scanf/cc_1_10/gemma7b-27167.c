//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void destroy(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        free((*arr)[i]);
        free(*arr);
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    int **arr = NULL;
    arr = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(10 * sizeof(int));
    }

    // Insert data into the array

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Search for an element in the array

    int element_to_search = 0;
    scanf("%d", &element_to_search);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == element_to_search)
            {
                printf("Element found at: (%d, %d)\n", i, j);
                destroy(arr, n);
                exit(0);
            }
        }
    }

    printf("Element not found\n");
    destroy(arr, n);

    return 0;
}