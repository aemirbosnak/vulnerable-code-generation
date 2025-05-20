#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void vulnerableFunction(int *arr, int size) {
    arr = realloc(arr, (size + 2) * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    arr[size] = 42;
    arr[size + 1] = 99;

    free(arr + 1); // Freeing part of the array

    printf("%d %d\n", arr[0], arr[size]); // Potential use-after-free here
}

int main() {
    int *array = malloc(sizeof(int) * 5);
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    array[0] = 10;
    array[1] = 20;
    array[2] = 30;
    array[3] = 40;
    array[4] = 50;

    vulnerableFunction(array, 5);

    free(array); // Freeing the entire array

    return 0;
}
