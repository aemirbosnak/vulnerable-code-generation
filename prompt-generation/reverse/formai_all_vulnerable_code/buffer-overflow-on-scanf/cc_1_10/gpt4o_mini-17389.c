//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to implement Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        // Flag to check if a swap has been made
        int swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        // If no elements were swapped, break
        if (swapped == 0) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to take user input for the array
void inputArray(int arr[], int n) {
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Main function
int main() {
    int n;

    // Prompt user for the number of elements
    printf("How many elements do you want to sort? ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Number of elements should be greater than 0.\n");
        return 1; // Exit with an error code
    }

    int arr[n]; // Declare an array of size n

    // Input the array elements
    inputArray(arr, n);

    // Display the original array
    printf("Original array:\n");
    printArray(arr, n);

    // Perform Bubble Sort
    bubbleSort(arr, n);

    // Display the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0; // Successful completion
}