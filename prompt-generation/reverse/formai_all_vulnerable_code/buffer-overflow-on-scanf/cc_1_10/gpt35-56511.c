//FormAI DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = NULL;
    int n, i;

    // get the number of integers to be allocated
    printf("Enter the number of integers to be allocated: ");
    scanf("%d", &n);

    // allocate memory for n integers
    p = (int*) malloc(n * sizeof(int));

    // check if allocation was successful
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // assign values to the allocated memory
    for (i = 0; i < n; i++) {
        *(p + i) = i + 1;
    }

    // print the values in the allocated memory
    printf("Values in the allocated memory:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(p + i));
    }

    // reallocate memory for twice the number of integers
    printf("\n\nReallocating memory for twice the number of integers\n");
    p = (int*) realloc(p, 2 * n * sizeof(int));

    // check if reallocation was successful
    if (p == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    // assign new values to the reallocated memory
    for (i = n; i < 2 * n; i++) {
        *(p + i) = i + 1;
    }

    // print the values in the reallocated memory
    printf("Values in the reallocated memory:\n");
    for (i = 0; i < 2 * n; i++) {
        printf("%d ", *(p + i));
    }

    // free the memory
    free(p);

    return 0;
}