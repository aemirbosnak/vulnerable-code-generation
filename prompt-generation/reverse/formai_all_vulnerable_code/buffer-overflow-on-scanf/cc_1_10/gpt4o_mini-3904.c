//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printArray(int arr[], int size);

int main() {
    int n, i;

    // Prompt user for the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input elements from user
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Displaying the original array
    printf("Original array:\n");
    printArray(arr, n);

    // Sorting the array
    quickSort(arr, 0, n - 1);

    // Displaying the sorted array
    printf("\nSorted array:\n");
    printArray(arr, n);

    // Free the dynamically allocated memory
    free(arr);
    
    return 0;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        // Recursively sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element
    int j;

    for (j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // increment index of smaller element
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i + 1] and arr[high] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}