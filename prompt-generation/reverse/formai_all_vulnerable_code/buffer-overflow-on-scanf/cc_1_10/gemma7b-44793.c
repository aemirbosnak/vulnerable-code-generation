//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: genius
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a 2D array to store the data
    int **arr = NULL;
    int n, m;

    // Get the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("Enter the number of columns: ");
    scanf("%d", &m);

    // Allocate memory for the array
    arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(m * sizeof(int));
    }

    // Fill the array with data
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Search for an element in the array
    int element;
    printf("Enter the element you want to search for: ");
    scanf("%d", &element);

    // Search for the element
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == element)
            {
                found = 1;
                break;
            }
        }
    }

    // Print the result
    if (found)
    {
        printf("The element %d has been found.\n", element);
    }
    else
    {
        printf("The element %d has not been found.\n", element);
    }

    // Free the memory
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}