//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        printf("Checking index %d: current value is %d\n", i, arr[i]);
        if (arr[i] == target) {
            return i; // return the index if found
        }
    }
    return -1; // return -1 if not found
}

// Function to print an array
void printArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, target;

    // Getting the size of the array from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Taking array input from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Display the array
    printArray(arr, n);

    // Asking for the target value to search
    printf("Enter the value to search for: ");
    scanf("%d", &target);

    // Performing linear search
    int result = linearSearch(arr, n, target);

    // Outputting the result
    if (result != -1) {
        printf("Value %d found at index %d.\n", target, result);
    } else {
        printf("Value %d not found in the array.\n", target);
    }

    return 0;
}