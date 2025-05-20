//Falcon-180B DATASET v1.0 Category: Memory management ; Style: beginner-friendly
/* This program demonstrates the use of dynamic memory allocation in C */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int *arr = (int *) malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Initialize the array with random values
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // Print the original array
    printf("Original array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array in ascending order
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}