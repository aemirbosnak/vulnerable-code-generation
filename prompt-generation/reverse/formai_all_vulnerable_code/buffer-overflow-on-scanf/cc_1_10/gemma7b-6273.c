//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **arr = NULL;
    int n = 0;

    // Allocate memory for the array
    arr = malloc(n * sizeof(char *));

    // Get the number of elements from the user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Create the array
    arr = realloc(arr, n * sizeof(char *));

    // Get the elements from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    // Search for an element in the array
    char element_to_search;
    printf("Enter the element to search for: ");
    scanf("%s", &element_to_search);

    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(arr[i], element_to_search) == 0)
        {
            found = 1;
            break;
        }
    }

    // Print the result
    if (found)
    {
        printf("Element found.\n");
    }
    else
    {
        printf("Element not found.\n");
    }

    // Free the memory
    free(arr);

    return 0;
}