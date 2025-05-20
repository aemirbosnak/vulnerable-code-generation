//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Function to print the array
void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to compare two elements (for quicksort)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high]; // pivot
        int i = (low - 1);     // Index of smaller element

        for (int j = low; j < high; j++) {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++; // increment index of smaller element
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        // Swap the pivot element with the element at index i+1
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        // Recursively sort elements before and after partition
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

// Function to fill the array with random numbers
void fillArrayWithRandomNumbers(int arr[], int size) {
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Assign a random number
    }
}

// Main function
int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the number of elements to sort (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Validate input
    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid number of elements. Please run the program again.\n");
        return 1;
    }

    // Fill the array with random numbers
    fillArrayWithRandomNumbers(arr, size);
    
    // Print the original array
    printf("Original ");
    printArray(arr, size);

    // Perform quicksort
    quickSort(arr, 0, size - 1);

    // Print the sorted array
    printf("Sorted ");
    printArray(arr, size);

    return 0;
}