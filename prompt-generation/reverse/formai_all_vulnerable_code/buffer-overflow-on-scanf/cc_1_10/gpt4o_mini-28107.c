//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

void fillArray(int *arr, int size);
void printArray(int *arr, int size);
int *createArray(int size);
void freeArray(int *arr);

int main() {
    int size;
    
    printf("Enter the number of elements you want in the array: ");
    scanf("%d", &size);

    // Creating a dynamic array
    int *myArray = createArray(size);
    if (myArray == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Filling the array with values
    fillArray(myArray, size);
    
    // Printing the array
    printf("The elements in the array are:\n");
    printArray(myArray, size);

    // Freeing the dynamic memory
    freeArray(myArray);

    return EXIT_SUCCESS;
}

// Function to create an array of a specific size
int *createArray(int size) {
    return (int *) malloc(size * sizeof(int));
}

// Function to fill the array with random values
void fillArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random value between 0 and 99
    }
}

// Function to print the elements of the array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to free the allocated memory
void freeArray(int *arr) {
    free(arr);
}