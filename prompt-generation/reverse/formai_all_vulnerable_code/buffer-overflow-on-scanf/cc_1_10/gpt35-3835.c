//FormAI DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {

    int* p = (int*) malloc(5 * sizeof(int)); // Allocate memory of 5 integers on heap
    if(p == NULL) { // Check if allocation was successful
        printf("Allocation unsuccessful!");
        exit(0);
    }

    printf("Memory allocated for 5 integers on heap.\n");

    // Get input from user
    for(int i = 0; i < 5; i++) {
        printf("Enter an integer for index %d: ", i);
        scanf("%d", (p+i));
    }

    printf("Input taken. Printing values...\n");
    for(int i = 0; i < 5; i++) {
        printf("Value at index %d: %d\n", i, *(p+i));
    }

    // Reallocate memory to store 10 integers
    int* q = (int*) realloc(p, 10 * sizeof(int));
    if(q == NULL) { // Check if reallocation was successful
        printf("Reallocation unsuccessful!");
        exit(0);
    }

    printf("Memory reallocated for 10 integers on heap.\n");

    // Get input from user for remaining memory
    for(int i = 5; i < 10; i++) {
        printf("Enter an integer for index %d: ", i);
        scanf("%d", (q+i));
    }

    printf("Input taken. Printing values...\n");
    for(int i = 0; i < 10; i++) {
        printf("Value at index %d: %d\n", i, *(q+i));
    }

    // Free allocated memory
    free(q);
    printf("Memory freed.\n");

    return 0;
}