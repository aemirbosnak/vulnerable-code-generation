//FormAI DATASET v1.0 Category: Memory management ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr, i, n;

    printf("Enter the number of integers to be stored in an array: ");
    scanf("%d", &n);

    // allocating memory dynamically using malloc()
    ptr = (int*) malloc(n * sizeof(int));

    // if memory cannot be allocated
    if(ptr == NULL) {
        printf("Error! Memory not allocated.");
        exit(0);
    }

    // initialize the array
    for(i = 0; i < n; ++i) {
        *(ptr + i) = i;
    }

    printf("The elements of the array are: ");
    for(i = 0; i < n; ++i) {
        printf("%d ", *(ptr + i));
    }

    // reallocate memory using realloc()
    int new_size = n + 2;
    ptr = realloc(ptr, new_size * sizeof(int));

    // if memory cannot be reallocated
    if(ptr == NULL) {
        printf("\nError! Memory not reallocated.");
        exit(0);
    }

    // initialize the new elements
    for(i = n; i < new_size; ++i) {
        *(ptr + i) = i;
    }

    printf("\nThe elements of the array after reallocation are: ");
    for(i = 0; i < new_size; ++i) {
        printf("%d ", *(ptr + i));
    }

    // free the dynamically allocated memory
    free(ptr);

    return 0;
}