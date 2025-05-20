//FormAI DATASET v1.0 Category: Memory management ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size;

    printf("Enter size of array: ");
    scanf("%d", &size);

    arr = (int*)malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Populating array with values from 1 to %d\n", size);

    for (int i = 0; i < size; i++) {
        arr[i] = i+1;
    }

    printf("Printing contents of array: ");

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nDoubling the size of array...\n");

    arr = (int*)realloc(arr, size * 2 * sizeof(int));

    if (arr == NULL) {
        printf("Memory reallocation failed");
        return 1;
    }

    printf("Populating new elements with values from %d to %d\n", size+1, size*2);

    for (int i = size; i < size*2; i++) {
        arr[i] = i+1;
    }

    printf("Printing contents of enlarged array: ");

    for (int i = 0; i < size*2; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    printf("\nMemory freed\n");

    return 0;
}