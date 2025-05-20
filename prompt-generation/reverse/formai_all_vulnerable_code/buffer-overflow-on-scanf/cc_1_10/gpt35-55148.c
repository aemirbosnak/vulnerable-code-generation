//FormAI DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr;

    // Allocate memory for 5 integers
    ptr = (int*)malloc(5 * sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Enter values into the allocated memory
    for (int i = 0; i < 5; i++) {
        printf("Enter value for element %d: ", i+1);
        scanf("%d", &ptr[i]);
    }

    // Display entered values
    printf("Allocated memory contents:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", ptr[i]);
    }

    // Increase the allocated memory to store 10 integers
    ptr = realloc(ptr, 10 * sizeof(int));

    if (ptr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    // Enter values into the newly allocated memory
    for (int i = 5; i < 10; i++) {
        printf("Enter value for element %d: ", i+1);
        scanf("%d", &ptr[i]);
    }

    // Display all entered values
    printf("Allocated memory contents:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", ptr[i]);
    }

    // Free the allocated memory
    free(ptr);

    return 0;
}