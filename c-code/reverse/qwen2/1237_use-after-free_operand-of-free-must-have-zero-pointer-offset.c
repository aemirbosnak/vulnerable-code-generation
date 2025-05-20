#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void vulnerableFunction(int size) {
    int *ptr = (int *)malloc(size * sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Use the allocated memory
    for (int i = 0; i < size; i++) {
        ptr[i] = i + 1;
    }

    // Reallocate memory
    ptr = (int *)realloc(ptr, (size + 5) * sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "Realloc failed\n");
        return;
    }

    // Free part of the memory
    free(ptr + 2);

    // Use after free
    printf("%d\n", *(ptr + 3));

    free(ptr);
}

int main() {
    vulnerableFunction(10);
    return 0;
}
