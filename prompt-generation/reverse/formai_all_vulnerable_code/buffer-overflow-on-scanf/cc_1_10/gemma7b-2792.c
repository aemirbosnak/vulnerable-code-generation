//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int i, j, n, m;
    char c;

    // Create a 2D array
    int **arr = NULL;

    // Allocate memory for the 2D array
    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    // Initialize the 2D array
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = 0;
        }
    }

    // Read data from the input
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    // Allocate memory for the data
    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
    }

    // Read the data
    printf("Enter the data: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Print the data
    printf("The data is: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}