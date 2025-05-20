#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr, i, size = 10;

    arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < size; ++i) {
        arr[i] = i * i;
    }

    printf("Original array:\n");
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    size *= 2;
    arr = (int *)realloc(arr, size * sizeof(int));

    if (arr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    for (; i < size; ++i) {
        arr[i] = i * i * i;
    }

    printf("\n\nExtended array:\n");
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    free((void *)(&arr[size / 2]));

    printf("\n\nFreed a portion of the array.\n");

    free(arr);

    return 0;
}
