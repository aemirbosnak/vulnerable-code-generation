//Gemma-7B DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int *arr = NULL;
    int size = 0;
    int i = 0;

    // Allocate memory for the array
    arr = (int *)malloc(MAX_SIZE * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL)
    {
        fprintf(stderr, "Error allocating memory.");
        exit(1);
    }

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Check if the size is valid
    if (size <= 0 || size > MAX_SIZE)
    {
        fprintf(stderr, "Invalid size.");
        exit(1);
    }

    // Fill the array with numbers
    for (i = 0; i < size; i++)
    {
        printf("Enter the number for the array: ");
        scanf("%d", &arr[i]);
    }

    // Print the elements of the array
    for (i = 0; i < size; i++)
    {
        printf("The element of the array at index %d is: %d\n", i, arr[i]);
    }

    // Free the memory allocated for the array
    free(arr);

    return 0;
}