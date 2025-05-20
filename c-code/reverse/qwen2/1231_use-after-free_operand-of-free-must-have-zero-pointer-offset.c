#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    size_t initial_size = 5, new_size = 10;

    // Allocate initial memory
    arr = (int *)malloc(initial_size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    printf("Initial array: ");
    for (size_t i = 0; i < initial_size; ++i) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Resize memory
    arr = (int *)realloc(arr, new_size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        free(arr);
        return 1;
    }
    for (size_t i = initial_size; i < new_size; ++i) {
        arr[i] = i + 1;
    }
    printf("Resized array: ");
    for (size_t i = 0; i < new_size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free memory
    free(arr);

    return 0;
}
