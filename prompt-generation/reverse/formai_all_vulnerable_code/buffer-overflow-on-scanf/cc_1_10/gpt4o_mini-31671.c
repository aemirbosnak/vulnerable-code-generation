//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void quicksort(int *array, int low, int high);
int partition(int *array, int low, int high);
void printArray(int *array, int size);

int main() {
    int *array;
    int n, i;

    printf("Welcome to the Dynamic QuickSort Program!\n");
    printf("Enter the number of elements you wish to sort: ");
    
    // Dynamically inputting the size of the array
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input! Please enter a positive integer value.\n");
        return EXIT_FAILURE;
    }

    // Allocating memory for the array
    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Inputting the array elements from the user
    printf("Enter the elements (space-separated): ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &array[i]) != 1) {
            printf("Invalid input detected! Please ensure you enter integers.\n");
            free(array);
            return EXIT_FAILURE;
        }
    }

    printf("Unsorted array: ");
    printArray(array, n);
    
    // Calling quicksort
    quicksort(array, 0, n-1);

    printf("Sorted array: ");
    printArray(array, n);

    // Freeing allocated memory
    free(array);
    
    printf("Thank you for using the Dynamic QuickSort Program!\n");
    return EXIT_SUCCESS;
}

// Function to perform QuickSort
void quicksort(int *array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);

        quicksort(array, low, pi - 1);  // Before pi
        quicksort(array, pi + 1, high); // After pi
    }
}

// Function to partition the array
int partition(int *array, int low, int high) {
    int pivot = array[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (array[j] <= pivot) {
            i++; // increment index of smaller element
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    // Swap the pivot element with the element at index i + 1
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return (i + 1);
}

// Function to print the array
void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}