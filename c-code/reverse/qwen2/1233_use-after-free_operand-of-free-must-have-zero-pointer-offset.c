#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    size_t initial_size = 5;
    size_t new_size = 10;

    // Allocate initial memory
    arr = (int *)malloc(initial_size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize array elements
    for (size_t i = 0; i < initial_size; i++) {
        arr[i] = i + 1;
    }

    // Reallocate memory
    arr = (int *)realloc(arr, new_size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Realloc failed\n");
        free(arr);
        return 1;
    }

    // Introduce a subtle memory error: write beyond the newly allocated space
    arr[9] = 100; // This is out of bounds

    // Free only part of the memory
    free(arr + 2); // This will cause undefined behavior

    // Print array elements
    for (size_t i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free remaining memory
    free(arr);

    return 0;
}
