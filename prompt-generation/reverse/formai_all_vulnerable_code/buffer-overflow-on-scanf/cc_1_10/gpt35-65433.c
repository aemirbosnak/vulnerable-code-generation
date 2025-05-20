//FormAI DATASET v1.0 Category: Memory management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int *ptr = (int *)malloc(size * sizeof(int));

    if (ptr == NULL)
    {
        printf("Error! Unable to allocate memory.");
        exit(0);
    }

    // Input values into the array
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &ptr[i]);
    }

    // Output values of the array
    printf("The array elements are: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }

    // Dynamically reallocate memory for the array
    printf("\nEnter the new size of the array: ");
    scanf("%d", &size);
    ptr = realloc(ptr, size * sizeof(int));

    if (ptr == NULL)
    {
        printf("Error! Unable to reallocate memory.");
        exit(0);
    }

    // Input values into the resized array
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &ptr[i]);
    }

    // Output values of the resized array
    printf("The resized array elements are: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }

    // Free memory of the array
    free(ptr);

    return 0;
}