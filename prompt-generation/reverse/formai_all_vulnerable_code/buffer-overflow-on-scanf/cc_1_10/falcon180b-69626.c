//Falcon-180B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;
    int size = 0;

    // allocate memory dynamically
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    ptr = (int*) malloc(size * sizeof(int));

    if (ptr == NULL) {
        printf("Memory could not be allocated.\n");
        exit(0);
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &ptr[i]);
    }

    // print the array
    printf("The array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // reallocate memory
    size += 5;
    ptr = (int*) realloc(ptr, size * sizeof(int));

    if (ptr == NULL) {
        printf("Memory could not be reallocated.\n");
        exit(0);
    }

    // add new elements to the array
    printf("Enter the new elements of the array:\n");
    for (int i = size - 5; i < size; i++) {
        scanf("%d", &ptr[i]);
    }

    // print the updated array
    printf("The updated array is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // free the memory
    free(ptr);
    return 0;
}