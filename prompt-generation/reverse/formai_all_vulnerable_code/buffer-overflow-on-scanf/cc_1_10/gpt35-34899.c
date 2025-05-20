//FormAI DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Hey there! I'm a cheerful Memory Management Program!\n");

    // Allocate memory for an integer
    int *num = (int*) malloc(sizeof(int));
    if (num == NULL) {
        printf("Oops, something went wrong with the memory allocation!\n");
        return 1;
    }

    // Read in user input for num
    printf("Please enter an integer: ");
    scanf("%d", num);

    // Allocate memory for an array of 10 integers
    int *arr = (int*) calloc(10, sizeof(int));
    if (arr == NULL) {
        printf("Oops, something went wrong with the memory allocation!\n");
        free(num); // Free previously allocated memory before exiting
        return 1;
    }

    // Fill the array with multiples of num
    for (int i = 0; i < 10; i++) {
        arr[i] = (*num) * (i+1);
    }

    // Print out the array values
    printf("The array values are: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reallocate memory for the array of 20 integers
    arr = (int*) realloc(arr, 20*sizeof(int));
    if (arr == NULL) {
        printf("Oops, something went wrong with the memory reallocation!\n");
        return 1;
    }

    // Fill the new elements of the array with multiples of num
    for (int i = 10; i < 20; i++) {
        arr[i] = (*num) * (i+1);
    }

    // Print out the updated array values
    printf("The updated array values are: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(num);
    free(arr);

    printf("Yay! The Memory Management Program completed successfully!\n");
    return 0;
}