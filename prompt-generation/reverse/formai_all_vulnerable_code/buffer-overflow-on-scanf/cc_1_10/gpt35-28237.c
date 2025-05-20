//FormAI DATASET v1.0 Category: Memory management ; Style: safe
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

// forward declarations
int allocate_array(int **arr, int size);
void free_array(int *arr);

int main(void) {
    int *arr;
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (allocate_array(&arr, size) != 0) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    // populate the array
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    // print the array
    printf("Array contents:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free_array(arr);

    return 0;
}

// dynamically allocate an array of int
// returns 0 on success, non-zero on failure
int allocate_array(int **arr, int size) {
    if (size > MAX_SIZE) {
        return -1;
    }

    *arr = malloc(size * sizeof(int));

    if (*arr == NULL) {
        return -1;
    }

    return 0;
}

// free a dynamically allocated array
void free_array(int *arr) {
    free(arr);
}