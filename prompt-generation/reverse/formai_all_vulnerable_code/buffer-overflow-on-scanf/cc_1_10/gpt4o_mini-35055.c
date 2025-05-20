//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    char ch;
    printf("Starting Bubble Sort...\n");
    for (i = 0; i < n-1; i++) {
        // Optimization: Flag to check if any swapping occurs
        int swapped = 0;
        printf("Pass %d: ", i + 1);
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
            printf("%d ", arr[j]);
        }
        printf("%d\n", arr[n-i-1]); // Print last unsorted element
        // Ask user if they want to see the next pass
        if (swapped) {
            printf("Press Enter to continue to the next pass...\n");
            while ((ch = getchar()) != '\n' && ch != EOF); // Clear the input buffer
        } else {
            break; // If no swapping, array is sorted
        }
    }
    printf("Array sorted!\n");
}

// Function to display the array
void displayArray(int arr[], int n) {
    printf("Current array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to take user input
void inputArray(int arr[], int n) {
    printf("Please enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int main() {
    int n;
    printf("Welcome to the Bubble Sort Visualization Program!\n");
    printf("How many elements do you want to sort? (up to 100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("The number of elements must be between 1 and 100.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    inputArray(arr, n);
    displayArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    displayArray(arr, n);
    
    free(arr);
    return 0;
}