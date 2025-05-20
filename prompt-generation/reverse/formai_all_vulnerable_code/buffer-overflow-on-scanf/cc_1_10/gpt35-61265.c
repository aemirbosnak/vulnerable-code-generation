//FormAI DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, *new_ptr;
    int i, n;

    // Get the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    ptr = (int*)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }

    // Input elements into the array
    printf("Enter %d elements into the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    // Display the contents of the array
    printf("\nThe elements entered are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    // Reallocate memory dynamically for array expansion
    printf("\n\nEnter the new size of the array: ");
    scanf("%d", &n);
    new_ptr = (int*)realloc(ptr, n * sizeof(int));

    // Check if memory reallocation was successful
    if (new_ptr == NULL) {
        printf("Memory reallocation failed!\n");
        exit(0);
    } else {
        ptr = new_ptr; // Set the original pointer to the new memory location
    }

    // Input new elements into the expanded array
    printf("Enter %d new elements into the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    // Display the contents of the expanded array
    printf("\nThe new elements entered are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    // Free the allocated memory
    free(ptr);
    ptr = NULL;

    return 0;
}