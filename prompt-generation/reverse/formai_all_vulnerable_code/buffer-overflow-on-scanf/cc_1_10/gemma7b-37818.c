//Gemma-7B DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

void main()
{
    // Define an array of strings
    char **arr = NULL;
    int i, j, k, n, size = 0;

    // Allocate memory for the array
    arr = (char **)malloc(MAX_SIZE * sizeof(char *));

    // Get the number of strings from the user
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    // Allocate memory for each string
    for (i = 0; i < n; i++)
    {
        arr[i] = (char *)malloc(MAX_SIZE * sizeof(char));
    }

    // Get the strings from the user
    for (i = 0; i < n; i++)
    {
        printf("Enter the string: ");
        scanf("%s", arr[i]);
    }

    // Find the longest string
    k = 0;
    for (i = 0; i < n; i++)
    {
        if (strlen(arr[i]) > k)
        {
            k = strlen(arr[i]);
        }
    }

    // Print the longest string
    printf("The longest string is: %s", arr[k]);

    // Free the memory allocated for the array
    for (i = 0; i < n; i++)
    {
        free(arr[i]);
    }

    free(arr);

    return;
}