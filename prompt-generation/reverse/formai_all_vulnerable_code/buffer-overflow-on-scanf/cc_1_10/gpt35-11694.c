//FormAI DATASET v1.0 Category: Memory management ; Style: bold
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, i, j, count = 0;
    int *arr;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    // Allocating memory dynamically for the array
    arr = (int*)malloc(size * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    printf("\nDynamic memory allocation for array successful!\n\n");

    // Storing values into the array
    for (i = 0; i < size; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Displaying elements of the array
    printf("\nArray elements:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    // Counting even numbers
    for (j = 0; j < size; j++)
    {
        if (arr[j] % 2 == 0)
        {
            count++;
        }
    }

    // Reallocating memory for even numbers only
    arr = (int*)realloc(arr, count * sizeof(int));

    if (arr == NULL)
    {
        printf("\nMemory allocation failed!\n");
        exit(0);
    }

    printf("\nDynamic memory reallocation for even numbers successful!\n\n");

    printf("Even numbers:\n");

    // Storing even numbers in the array
    j = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            arr[j] = arr[i];
            j++;
            printf("%d ", arr[i]);
        }   
    }

    // Displaying even numbers from the array
    printf("\nArray elements with only even numbers:\n");
    for (i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }

    // Freeing dynamically allocated memory
    free(arr);
    arr = NULL;

    return 0;
}