//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printArray(int arr[], int size);

int main() {
    // Get ready to sort with excitement! 🎉
    int n; // Size of the array
    printf("Welcome to the Ultimate QuickSort Experience!\n");
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);
    
    // Dynamic memory allocation for the array
    int *arr = (int*) malloc(n * sizeof(int));
    
    // Check if memory allocation succeeded
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    // Seed the random number generator for unique values every run
    srand(time(0));
    
    // Fill the array with random numbers
    printf("Generating %d random numbers...\n", n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Values between 0 and 999
    }
    
    printf("Array before sorting:\n");
    printArray(arr, n);
    
    // Let the sorting begin! 🎊
    printf("Sorting the array using QuickSort...\n");
    quickSort(arr, 0, n - 1);
    
    // Display the sorted array
    printf("Array after sorting:\n");
    printArray(arr, n);
    
    // Free up the memory
    free(arr);
    printf("Memory freed. Thank you for playing with sorting! Bye! 👋\n");

    return 0;
}

// Function to perform QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    // Set the last element as the pivot
    int pivot = arr[high];
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Return the partitioning index
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}