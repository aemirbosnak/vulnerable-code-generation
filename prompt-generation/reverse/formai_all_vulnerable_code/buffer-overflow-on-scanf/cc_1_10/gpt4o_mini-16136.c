//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to perform bubble sort on the array
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        // This variable helps to detect if any swapping has occurred
        swapped = 0;

        for (j = 0; j < n - i - 1; j++) {
            // If the current element is greater than the next one, swap them
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set swapped as true
            }
        }
        
        // If no two elements were swapped by inner loop, then the array is sorted
        if (swapped == 0) {
            break;
        }
    }
}

// Function to print the array nicely
void printArray(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nThank you for viewing the array!\n");
}

// Main function to drive the program
int main() {
    printf("Welcome to the Grateful Sorting Program!\n\n");

    // Let's make space for the user to input their array size
    int n;
    printf("Please enter the number of elements in your array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Oh dear! The number of elements should be positive. Please run the program again with a valid number.\n");
        return 1; // Exit if an invalid number is given
    }

    // Dynamic memory allocation for the array
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Oops! Memory allocation failed. Please check your system resources.\n");
        return 1; // Exit if memory allocation fails
    }

    // Graciously ask the user to fill the array with numbers
    printf("Thank you! Now, please input your %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nYour array before sorting:\n");
    printArray(arr, n);

    // We are so grateful to be able to sort this array!
    bubbleSort(arr, n);
    
    printf("\nThe sorted array is:\n");
    printArray(arr, n);

    // A sweet goodbye
    printf("Thank you for using the Grateful Sorting Program! Have a wonderful day!\n");

    // Free the dynamically allocated memory
    free(arr);
    return 0;
}