//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: beginner-friendly
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // Loop through each element in the array
    for (i = 0; i < n - 1; i++) {
        // Last i elements are already sorted
        for (j = 0; j < n - i - 1; j++) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Ask the user for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Check if the number is valid
    if (n <= 0) {
        printf("Please enter a valid number of elements.\n");
        return 1; // Exit the program with an error code
    }

    int arr[n]; // Declare the array

    // Get the array values from the user
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("Original array:\n");
    printArray(arr, n);

    // Sort the array using bubble sort algorithm
    bubbleSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);
    
    return 0; // Indicate that the program ended successfully
}