//FormAI DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, *new_ptr, n, i;

    printf("Enter the number of integers to allocate memory for: ");
    scanf("%d", &n);

    // Allocate memory for n integers
    ptr = (int*) malloc(n * sizeof(int));

    // Check if allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        exit(1);
    }

    // Prompt user to enter n integers
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    // Display the n integers entered by the user
    printf("You entered: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Prompt user to enter additional memory to allocate
    printf("Enter the additional number of integers to allocate memory for: ");
    scanf("%d", &n);

    // Reallocate memory for n additional integers
    new_ptr = (int*) realloc(ptr, (n * sizeof(int)));

    // Check if reallocation was successful
    if (new_ptr == NULL) {
        printf("Memory reallocation failed. Exiting program.\n");
        exit(1);
    }

    ptr = new_ptr;

    // Prompt user to enter n additional integers
    printf("Enter %d additional integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    // Display all n + additional integers entered by the user
    printf("You entered: ");
    for (i = 0; i < (n + i); i++) {
        printf("%d ", ptr[i]);
    }

    // Free allocated memory
    free(ptr);

    return 0;
}