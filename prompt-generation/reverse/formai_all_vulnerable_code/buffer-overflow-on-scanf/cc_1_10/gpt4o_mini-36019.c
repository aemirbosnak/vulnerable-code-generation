//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);
void swap(int *xp, int *yp);

int main() {
    int n, i;

    // Let’s start this tragic tale of sorting!
    printf("Oh my goodness! What a chaotic array we have! How many elements shall we sort? (Enter a positive number): ");
    
    // Take user input for the number of elements 
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Wait a minute! That is not a valid number! Let's end this madness!\n");
        exit(EXIT_FAILURE);
    }

    // Create an array of the specified size
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Oh no! Memory allocation failed! What a disaster!\n");
        exit(EXIT_FAILURE);
    }

    printf("Now, please enter %d integers for the array, and brace yourself for the chaos!\n", n);
    
    // Populating the array with user input
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Oh no! That's not a number! Let's stop this madness!\n");
            free(arr);
            exit(EXIT_FAILURE);
        }
    }

    printf("Before sorting! What a chaotic sight to behold!\n");
    printArray(arr, n);

    // Sorting starts here! Hold on tight!
    printf("Sorting the array... What will happen next!? \n");
    bubbleSort(arr, n);

    // Sorted array 
    printf("After sorting! The horror! What did we just witness!? \n");
    printArray(arr, n);

    // Free the allocated memory
    free(arr);
    return 0;
}

// A nightmarish function to sort the array using Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    int swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Let's hope for a miracle!
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Chaos ensues! We must swap!
                swap(&arr[j], &arr[j + 1]);
                swapped = 1; // We've disturbed the order!
            }
        }
        if (swapped == 0) {
            // If nothing was swapped, we might have swept the chaos under the rug!
            break;
        }
    }
}

// A simple yet frightful function to swap two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to print the array. Be brave!
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}