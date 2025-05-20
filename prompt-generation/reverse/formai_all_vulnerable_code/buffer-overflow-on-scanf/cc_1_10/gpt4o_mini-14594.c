//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to print the array
void printArray(int *arr, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to fill the array with random numbers
void fillArray(int *arr, int size, int max_value) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % max_value;
    }
}

// Bubble Sort implementation
void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to optimize bubble sort using a flag
void optimizedBubbleSort(int *arr, int size) {
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no two elements were swapped by the inner loop, then break
        if (!swapped) break;
    }
}

// Main function to demonstrate sorting algorithms
int main() {
    srand(time(NULL)); // Seed the random number generator

    int arr[MAX_SIZE];
    int n;

    // Taking user input for the size of the array
    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    
    // Validate the size of the array
    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid size! Please enter a number between 1 and %d\n", MAX_SIZE);
        return 1;
    }

    fillArray(arr, n, 100); // Filling the array with random numbers
    printArray(arr, n); // Print original array

    // Using bubble sort
    printf("Sorting using Bubble Sort...\n");
    optimizedBubbleSort(arr, n);
    printArray(arr, n); // Print sorted array

    // Re-filling the array for demonstration of qsort
    fillArray(arr, n, 100);
    printArray(arr, n); // Print original array again

    // Using qsort from stdlib
    printf("Sorting using qsort...\n");
    qsort(arr, n, sizeof(int), compare);
    printArray(arr, n); // Print sorted array

    // Done with sorting demonstration
    return 0;
}