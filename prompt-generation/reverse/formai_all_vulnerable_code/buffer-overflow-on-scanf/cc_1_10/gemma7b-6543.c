//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, found = 0;
    scanf("%d", &n);

    // Create a 2D array
    int **arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    // Populate the array
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Search for the target number
    scanf("%d", &k);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == k)
            {
                found = 1;
            }
        }
    }

    // Print the result
    if (found)
    {
        printf("Target number found.\n");
    }
    else
    {
        printf("Target number not found.\n");
    }

    // Free the memory
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}