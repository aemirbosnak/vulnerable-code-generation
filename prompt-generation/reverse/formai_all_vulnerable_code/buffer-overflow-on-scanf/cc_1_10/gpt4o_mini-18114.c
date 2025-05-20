//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;

    // Prompt the user for the size of the array
    printf("Enter the number of elements you wish to sort: ");
    scanf("%d", &n);
    
    // Check if the number of elements is positive
    if(n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    int arr[n];

    // Read the elements of the array
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("Original array: \n");
    printArray(arr, n);

    // Perform Bubble Sort
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}