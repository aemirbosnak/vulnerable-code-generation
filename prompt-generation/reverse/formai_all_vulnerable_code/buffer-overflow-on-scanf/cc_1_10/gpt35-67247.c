//FormAI DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

/* This program demonstrates a unique way of memory management
   by creating a dynamic array of integers with a custom size
   specified by the user */

int main() {

    int size;

    /* Take input from user to determine size of array */
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    /* Allocate memory to the array using malloc */
    int *array = (int*) malloc(size * sizeof(int));

    /* Ensure memory has been properly allocated */
    if (array == NULL) {
        printf("Error: Memory allocation failed.");
        exit(1);
    }

    /* Populate the array with even values */
    for (int i = 0; i < size; i++) {
        array[i] = i*2;
    }

    /* Print the contents of the array */
    printf("Array Contents:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    /* Use realloc to increase size of array by 5 */
    int newSize = size + 5;
    array = (int*) realloc(array, newSize * sizeof(int));

    /* Ensure memory has been properly re-allocated */
    if (array == NULL) {
        printf("Error: Memory reallocation failed.");
        exit(1);
    }

    /* Populate the new part of the array with odd values */
    for (int i = size; i < newSize; i++) {
        array[i] = (i*2) + 1;
    }

    /* Print the new contents of the array */
    printf("New Array Contents:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    /* Free memory allocated to the array */
    free(array);

    return 0;
}