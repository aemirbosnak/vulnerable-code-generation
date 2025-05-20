//FormAI DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;

    printf("Enter the number of integers you want to store: ");
    scanf("%d", &size);

    int* ptr = (int*)malloc(size * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    printf("Memory allocation successful!\n");

    printf("Enter %d integers:\n", size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("The integers you entered are:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }

    printf("\n");

    // Reallocate memory
    int new_size;

    printf("Enter the new size: ");
    scanf("%d", &new_size);

    ptr = (int*)realloc(ptr, new_size * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory reallocation failed!\n");
        exit(0);
    }

    printf("Memory reallocation successful!\n");

    printf("Enter %d integers:\n", new_size);

    for (int i = 0; i < new_size; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("The integers you entered are:\n");

    for (int i = 0; i < new_size; i++)
    {
        printf("%d ", ptr[i]);
    }

    printf("\n");

    // Free memory
    free(ptr);

    printf("Memory freed successfully!\n");

    return 0;
}