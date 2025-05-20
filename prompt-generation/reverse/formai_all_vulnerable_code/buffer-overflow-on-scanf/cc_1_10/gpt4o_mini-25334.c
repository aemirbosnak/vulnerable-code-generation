//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);

int main() {
    int n, i;

    // Ask user for the number of elements
    printf("Welcome to the Sorting Program!\n");
    printf("Please enter the number of elements you wish to sort: ");
    scanf("%d", &n);

    // Dynamic memory allocation for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1; // Exit with error code if allocation fails
    }

    // User input for array elements
    printf("Please enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nYou entered the following array:\n");
    printArray(arr, n);

    // Call bubble sort function
    bubbleSort(arr, n);

    printf("\nSorted array in ascending order:\n");
    printArray(arr, n);

    // Freeing dynamically allocated memory
    free(arr);

    return 0;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    // Traverse through all array elements
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // To check if a swap occurred
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Indicate a swap has occurred
            }
        }
        // If no two elements were swapped by inner loop, break
        if (swapped == 0) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); // Newline for better readability
}