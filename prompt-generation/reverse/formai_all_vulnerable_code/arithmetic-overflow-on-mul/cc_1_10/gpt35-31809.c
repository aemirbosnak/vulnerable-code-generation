//FormAI DATASET v1.0 Category: Sorting ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a macro to generate a random number
#define RANDOM_NUM ((int)(rand() * 1000))

int main() {

    // Print an introductory message
    printf("Welcome to the mind-bending sorting program!\n");

    // Generate an array of 10 random numbers
    int arr[10];
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        arr[i] = RANDOM_NUM;
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using bubble sort
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 10-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        // Print the array after each iteration of the outer loop
        printf("Array after iteration %d:\n", i+1);
        for(int k = 0; k < 10; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    // Print the final sorted array
    printf("Sorted array:\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print a closing message
    printf("Thank you for using the mind-bending sorting program!\n");

    return 0;
}