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

    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }

    printf("Original array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    arr = (int *)realloc(arr, 3 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Realloc failed\n");
        free(arr);
        return 1;
    }

    printf("Array after realloc: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Use-after-free vulnerability
    printf("Accessing freed element: %d\n", arr[2]);

    int *temp = (int *)malloc(2 * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Temporary memory allocation failed\n");
        free(arr);
        return 1;
    }

    temp[0] = arr[0];
    temp[1] = arr[1];

    printf("Temp array: %d %d\n", temp[0], temp[1]);

    free(temp);
    free(arr);

    return 0;
}
