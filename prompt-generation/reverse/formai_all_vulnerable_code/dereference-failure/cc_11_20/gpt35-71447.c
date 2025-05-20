//FormAI DATASET v1.0 Category: Memory management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, *ptr, **pptr;

    // Allocate memory for 5 integers
    ptr = (int*) malloc(5*sizeof(int));

    // Check if allocation was successful
    if (ptr == NULL) {
        printf("Error: Out of memory!\n");
        return 1;
    }

    // Initialize the integers to 0
    for (i = 0; i < 5; i++) {
        *(ptr+i) = 0;
    }

    // Allocate memory for 3 pointers to int
    pptr = (int**) malloc(3*sizeof(int*));

    // Check if allocation was successful
    if (pptr == NULL) {
        printf("Error: Out of memory!\n");
        return 1;
    }

    // Initialize the pointers to the allocated integers
    for (i = 0; i < 3; i++) {
        *(pptr+i) = (int*) malloc(5*sizeof(int));
        // Check if allocation was successful
        if (*(pptr+i) == NULL) {
            printf("Error: Out of memory!\n");
            return 1;
        }
    }

    // Initialize the integers pointed to by the pointers
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            *(*(pptr+i)+j) = i*j;
        }
    }

    // Print the integers pointed to by the pointers
    for (i = 0; i < 3; i++) {
        printf("Pointer %d:\n", i+1);
        for (j = 0; j < 5; j++) {
            printf("%d ", *(*(pptr+i)+j));
        }
        printf("\n");
    }

    // Free the memory allocated for the integers
    free(ptr);

    // Free the memory allocated for the pointers to the integers
    for (i = 0; i < 3; i++) {
        free(*(pptr+i));
    }
    free(pptr);

    return 0;
}