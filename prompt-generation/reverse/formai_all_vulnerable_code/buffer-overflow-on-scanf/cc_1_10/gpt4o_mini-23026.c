//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

// Function prototypes
void bubbleSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void generateRandomArray(int arr[], int size);
void printArray(int arr[], int size);

// Main function
int main() {
    int arrBubble[MAX_SIZE], arrQuick[MAX_SIZE];
    int size;
    
    // Get the size of array from the user
    printf("Enter the size of the array (up to %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    // Generate a random array for both sorting algorithms
    generateRandomArray(arrBubble, size);
    for (int i = 0; i < size; i++) {
        arrQuick[i] = arrBubble[i];  // Copying the array for quick sort
    }

    // Measure time for Bubble Sort
    clock_t startBubble = clock();
    bubbleSort(arrBubble, size);
    clock_t endBubble = clock();
    
    double timeBubble = ((double)(endBubble - startBubble)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took: %f seconds\n", timeBubble);
    // Uncomment to see the sorted array
    // printArray(arrBubble, size);

    // Measure time for Quick Sort
    clock_t startQuick = clock();
    quickSort(arrQuick, 0, size - 1);
    clock_t endQuick = clock();
    
    double timeQuick = ((double)(endQuick - startQuick)) / CLOCKS_PER_SEC;
    printf("Quick Sort took: %f seconds\n", timeQuick);
    // Uncomment to see the sorted array
    // printArray(arrQuick, size);

    return 0;
}

// Implementing Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Implementing Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap pivot
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Function to generate a random array
void generateRandomArray(int arr[], int size) {
    srand(time(NULL)); // Seed for random number generator
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // Random numbers from 0 to 9999
    }
}

// Function to print the array (for debugging purposes)
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}