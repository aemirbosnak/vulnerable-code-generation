//FormAI DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_elements;
    int* mem;

    printf("Enter the number of elements to allocate: ");
    scanf("%d", &num_elements);

    mem = (int*) malloc(num_elements * sizeof(int));

    if (!mem) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Memory allocation successful!\n");

    // Assign values to allocated memory
    for (int i = 0; i < num_elements; i++) {
        *(mem + i) = i * 2;
    }

    printf("Allocated memory contents:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", *(mem + i));
    }

    printf("\nEnter the number of elements to reallocate: ");
    scanf("%d", &num_elements);

    mem = (int*) realloc(mem, num_elements * sizeof(int));

    if (!mem) {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    printf("Memory reallocation successful!\n");

    // Assign values to reallocated memory
    for (int i = 0; i < num_elements; i++) {
        *(mem + i) = i + 5;
    }

    printf("Reallocated memory contents:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", *(mem + i));
    }

    free(mem);
    printf("\nMemory deallocated successfully!");

    return 0;
}