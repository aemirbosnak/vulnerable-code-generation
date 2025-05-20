//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to perform a bubble sort on an array
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to generate an array of random integers
void generateRandomArray(int arr[], int size, int upper_bound) {
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % upper_bound; // Populate with random integers
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Main function to execute sorting algorithms
int main() {
    int n;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Number of elements must be positive!\n");
        return EXIT_FAILURE;
    }

    int *array = (int *)malloc(n * sizeof(int));
    if (!array) {
        printf("Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    generateRandomArray(array, n, 100); // Fill the array with random numbers
    printf("Generated array before sorting:\n");
    printArray(array, n);

    // Sorting using Bubble Sort
    bubbleSort(array, n);
    printf("Sorted array using Bubble Sort:\n");
    printArray(array, n);

    // Reset array for using qsort
    generateRandomArray(array, n, 100); // Regenerate the random numbers
    printf("Generated array before sorting with qsort:\n");
    printArray(array, n);

    // Sorting using qsort
    qsort(array, n, sizeof(int), compare);
    printf("Sorted array using qsort:\n");
    printArray(array, n);

    // Clean up dynamically allocated memory
    free(array);
    return EXIT_SUCCESS;
}