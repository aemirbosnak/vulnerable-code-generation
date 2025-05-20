//FormAI DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    int *ptr1 = NULL;
    int *ptr2 = NULL;

    // Accepting size of integer array from user
    printf("Enter size of integer array: ");
    scanf("%d", &size);

    // Allocating memory dynamically using malloc()
    ptr1 = (int*) malloc(size * sizeof(int));

    if(ptr1 == NULL) {
        printf("Error! Memory not allocated.");
        exit(0);
    }

    // Accepting values from user to be stored in ptr1
    printf("\nEnter %d integers:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", (ptr1 + i));
    }

    // Printing the integers stored in ptr1
    printf("\nThe integers stored in ptr1 are:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", *(ptr1 + i));
    }

    // Reallocating memory dynamically using realloc()
    printf("\n\nEnter new size of integer array: ");
    scanf("%d", &size);

    ptr2 = (int*) realloc(ptr1, size * sizeof(int));

    if(ptr2 == NULL) {
        printf("Error! Memory not allocated.");
        exit(0);
    }

    // Accepting additional values from user to be stored in ptr2
    printf("\nEnter additional %d integers:\n", size - (size / 2));
    for(int i = size / 2; i < size; i++) {
        scanf("%d", (ptr2 + i));
    }

    // Printing the integers stored in ptr2
    printf("\nThe integers stored in ptr2 are:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", *(ptr2 + i));
    }

    // Freeing up dynamically allocated memory using free()
    free(ptr2);
    ptr1 = ptr2 = NULL;

    return 0;
}