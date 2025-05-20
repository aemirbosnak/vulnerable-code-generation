#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    size_t n = 5;

    // Allocate initial memory
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize array elements
    for (size_t i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Print array elements
    printf("Initial array: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reallocate more memory
    n += 3;
    arr = (int *)realloc(arr, n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        free(arr);
        return 1;
    }

    // Initialize new elements
    for (size_t i = 5; i < n; i++) {
        arr[i] = i + 1;
    }

    // Print updated array elements
    printf("Updated array: ");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);

    return 0;
}
