#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize array
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    printf("Original array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reallocate memory to hold 10 elements
    int *temp = (int *)realloc(arr, 10 * sizeof(int));
    if (temp == NULL) {
        free(arr);
        fprintf(stderr, "Realloc failed\n");
        return 1;
    } else {
        arr = temp;
    }

    // Initialize new elements
    for (int i = 5; i < 10; i++) {
        arr[i] = i + 6;
    }

    printf("Reallocated array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free first half of the array
    free(arr);

    // Attempt to access freed memory
    printf("Trying to access freed memory...\n");
    for (int i = 5; i < 10; i++) {
        printf("%d ", arr[i]); // This should cause undefined behavior
    }
    printf("\n");

    return 0;
}
