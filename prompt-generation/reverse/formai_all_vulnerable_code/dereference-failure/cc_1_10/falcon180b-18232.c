//Falcon-180B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    free(ptr);
}

int main() {
    int i, j;
    char *str1, *str2;

    // Allocate memory for an array of integers
    int *arr1 = (int *)my_malloc(10 * sizeof(int));
    if (arr1 == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    // Initialize the array
    for (i = 0; i < 10; i++) {
        arr1[i] = i;
    }

    // Print the array
    printf("Array 1: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Allocate memory for an array of characters
    str1 = (char *)my_malloc(20 * sizeof(char));
    if (str1 == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    // Initialize the array
    for (i = 0; i < 20; i++) {
        str1[i] = 'a' + i;
    }

    // Print the array
    printf("String 1: ");
    for (i = 0; i < 20; i++) {
        printf("%c ", str1[i]);
    }
    printf("\n");

    // Allocate memory for another array of characters
    str2 = (char *)my_malloc(30 * sizeof(char));
    if (str2 == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    // Initialize the array
    for (i = 0; i < 30; i++) {
        str2[i] = 'a' + i;
    }

    // Print the array
    printf("String 2: ");
    for (i = 0; i < 30; i++) {
        printf("%c ", str2[i]);
    }
    printf("\n");

    // Free the allocated memory
    my_free(arr1);
    my_free(str1);
    my_free(str2);

    return 0;
}