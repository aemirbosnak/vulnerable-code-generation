//FormAI DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, *ptr2; // two integer pointers
    int num;

    printf("Enter the size of the integer array: ");
    scanf("%d", &num);

    // allocate memory dynamically
    ptr = (int*) malloc(num * sizeof(int));

    // check if memory has been successfully allocated
    if(ptr == NULL) {
        printf("Error! Memory not allocated.\n");
        exit(0);
    }

    // fill the array with random integers
    for(int i = 0; i < num; i++) {
        *(ptr + i) = rand() % 100;
    }

    // print the array
    printf("\nElements of the integer array:\n");
    for(int i = 0; i < num; i++) {
        printf("%d ", *(ptr + i));
    }

    // reallocate memory
    printf("\nEnter new size for the integer array: ");
    scanf("%d", &num);

    ptr2 = (int*) realloc(ptr, num * sizeof(int));

    // check if memory has been successfully reallocated
    if(ptr2 == NULL) {
        printf("Error! Memory not reallocated.\n");
        exit(0);
    } else {
        ptr = ptr2;
    }

    // fill the reallocated array with random integers
    for(int i = 0; i < num; i++) {
        *(ptr + i) = rand() % 100;
    }

    // print the reallocated array
    printf("\nElements of the reallocated integer array:\n");
    for(int i = 0; i < num; i++) {
        printf("%d ", *(ptr + i));
    }

    // free the allocated memory
    free(ptr);

    return 0;
}