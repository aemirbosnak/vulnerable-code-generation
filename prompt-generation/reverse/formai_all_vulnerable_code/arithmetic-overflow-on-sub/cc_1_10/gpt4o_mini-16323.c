//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array for QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = (low - 1);      // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Recursively sort elements before partition
        quickSort(arr, pi + 1, high); // Recursively sort elements after partition
    }
}

// Function to display the elements of the array
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;

    // Seed for random number generation
    srand(time(0));

    // Getting the number of elements in the array from user
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Generating random numbers to fill the array
    printf("Generated array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Filling with random numbers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sorting the array
    quickSort(arr, 0, n - 1);

    // Displaying sorted array
    printf("Sorted array:\n");
    displayArray(arr, n);

    // Freeing allocated memory
    free(arr);
    
    return 0;
}