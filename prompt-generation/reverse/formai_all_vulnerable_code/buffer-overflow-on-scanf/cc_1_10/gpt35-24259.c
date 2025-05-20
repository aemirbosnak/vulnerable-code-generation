//FormAI DATASET v1.0 Category: Memory management ; Style: beginner-friendly
/**
 * This program demonstrates dynamic memory allocation and deallocation using C's built-in
 * memory management functions, malloc() and free().
 * 
 * The user is prompted to enter the size of an array, and that size is used to allocate memory
 * for an integer array using malloc(). The user then enters the values to be stored in the array
 * and the array is printed to the console. Finally, the memory is deallocated using free().
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, i;
    int *arr;

    // Prompt user for size of array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for array
    arr = (int*)malloc(size * sizeof(int));

    // Check if memory was allocated successfully
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Prompt user to enter values for array
    printf("Enter %d values for the array:\n", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Print array to console
    printf("The array is: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Deallocate memory for array
    free(arr);

    return 0;
}