//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For the boolean type

void displayArray(int arr[], int size) {
    // Display the current state of the array
    printf("Current Array State: \n");
    for (int i = 0; i < size; i++) {
        // Display each element with a fascinating format
        printf("[ %d ] ", arr[i]);
        // Insert some artistic ASCII effects
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n==============================\n");
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        // Perform the inner loop to compare adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next one
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;

                // Display the current state with every swap
                displayArray(arr, n);
            }
        }
        // If no elements were swapped, the array is sorted
        if (!swapped)
            break;
    }
}

// Function to take input from the user
void inputArray(int arr[], int n) {
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

// Main function
int main() {
    int n;

    printf("Welcome to the Irregular Sorting Program! 🎉\n");
    printf("==========================================\n");
    
    // Ask for the size of the array
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Input the elements into the array
    inputArray(arr, n);
    
    // Display the initial array
    displayArray(arr, n);
    
    // Start the sorting process
    printf("Starting the sorting process...\n");
    bubbleSort(arr, n);
    
    // Final output of the sorted array
    printf("Sorting complete! Here is the sorted array:\n");
    displayArray(arr, n);

    // Free the dynamically allocated memory
    free(arr);
    printf("Memory has been freed.\n");

    return 0;
}