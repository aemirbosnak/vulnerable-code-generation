//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int size, int target, int *comparisons) {
    *comparisons = 0; // Initialize comparison count
    for (int i = 0; i < size; i++) {
        (*comparisons)++; // Increment the comparisons counter
        if (arr[i] == target) {
            return i; // Return index if target is found
        }
    }
    return -1; // Return -1 if target is not found
}

void fillArray(int arr[], int size) {
    printf("Enter %d elements of the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int main() {
    int size;

    // Ask user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    // Allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Fill the array with user input
    fillArray(arr, size);
    
    // Print the current elements of the array
    printArray(arr, size);

    // Ask for the target value to search
    int target;
    printf("Enter the value to search for: ");
    scanf("%d", &target);

    // Perform the search
    int comparisons = 0;
    int result = linearSearch(arr, size, target, &comparisons);

    // Output the results
    if (result != -1) {
        printf("Value %d found at index %d.\n", target, result);
    } else {
        printf("Value %d not found in the array.\n", target);
    }
    
    // Display the number of comparisons made
    printf("Total comparisons made: %d\n", comparisons);

    // Free the allocated memory
    free(arr);
    return 0;
}