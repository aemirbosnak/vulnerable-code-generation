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

    arr = (int *)realloc(arr, 10 * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Realloc failed\n");
        free(arr);
        return 1;
    }

    for (int i = 5; i < 10; i++) {
        arr[i] = i + 1;
    }

    printf("First five elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Last five elements: ");
    for (int i = 5; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Intentionally introduce a use-after-free vulnerability
    free(&arr[5]);

    printf("Accessing freed memory: %d\n", arr[5]); // Use-after-free

    free(arr);

    return 0;
}
