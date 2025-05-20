//FormAI DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {

    // Allocate dynamic memory using malloc()
    int* ptr = (int*) malloc(5 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation error!");
        exit(0);
    }

    // Entering values in the allocated memory
    printf("Enter 5 integer values: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &(*(ptr + i)));
    }

    // Displaying the values entered by the user
    printf("Entered values: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }

    // Reallocate the memory using realloc()
    ptr = (int*) realloc(ptr, 10 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory reallocation error!");
        free(ptr);
        exit(0);
    }

    // Entering more values in the newly allocated memory
    printf("\n\nEnter 5 more integer values: ");
    for (int i = 5; i < 10; i++) {
        scanf("%d", &(*(ptr + i)));
    }

    // Displaying the new values entered by the user
    printf("Newly entered values: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(ptr + i));
    }

    // Free the dynamically allocated memory using free()
    free(ptr);

    printf("\n\nMemory freed successfully!");

    return 0;
}