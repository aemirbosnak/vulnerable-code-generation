//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void quickSort(int *array, int low, int high);
int partition(int *array, int low, int high);
void printArray(int *array, int size);
void swap(int *a, int *b);

int main() {
    int n;

    // User input for the size of the array.
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamic memory allocation for the array.
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit on memory allocation failure.
    }

    // Input the elements of the array.
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Sort the array using QuickSort.
    quickSort(array, 0, n - 1);

    // Print the sorted array.
    printf("Sorted array:\n");
    printArray(array, n);

    // Free allocated memory.
    free(array);
    return 0;
}

// QuickSort function.
void quickSort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        // Recursively sort elements before
        // partition and after partition.
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Function to partition the array.
int partition(int *array, int low, int high) {
    int pivot = array[high]; // Pivot
    int i = (low - 1); // Index of smaller element
    for (int j = low; j < high; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (array[j] <= pivot) {
            i++; // increment index of smaller element
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

// Function to swap two elements.
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to print the array.
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}