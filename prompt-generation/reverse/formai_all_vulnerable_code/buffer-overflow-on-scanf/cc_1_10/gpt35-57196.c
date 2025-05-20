//FormAI DATASET v1.0 Category: Memory management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int *ptr;
    int size, i, sum = 0;

    // Getting size of array from user
    printf("Enter the size of array: ");
    scanf("%d", &size);

    // Checking if size is valid
    if(size > MAX_SIZE)
    {
        printf("Error: Size is too large!\n");
        exit(0);
    }

    // Allocating memory dynamically
    ptr = (int *) malloc(size * sizeof(int));

    if(ptr == NULL) // Checking if memory is allocated sucessfully
    {
        printf("Error: Memory not allocated!\n");
        exit(0);
    }

    // Taking input for array elements
    printf("Enter the elements of the array:\n");
    for(i = 0; i < size; i++)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    // Printing array elements
    printf("Array elements are: ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", *(ptr + i));
    }

    // Printing sum of array elements
    printf("\nSum of array elements is: %d", sum);

    // Freeing dynamic memory
    free(ptr);
    ptr = NULL;

    return 0;
}