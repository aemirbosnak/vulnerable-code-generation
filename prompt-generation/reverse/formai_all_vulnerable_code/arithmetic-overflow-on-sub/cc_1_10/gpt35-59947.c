//FormAI DATASET v1.0 Category: Searching algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function for searching an element in an array using binary search
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at middle point
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // Element not found in the array
    return -1;
}

// Main function
int main() {
    int n, x;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));

    // Read the elements of the array from the user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in ascending order
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Read the element to be searched from the user
    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    // Call the binary search function to search the element in the array
    int result = binarySearch(arr, 0, n-1, x);

    // Check if the element was found or not
    if (result == -1) {
        printf("Element not found in the array.");
    } else {
        printf("Element found at index %d in the array.", result);
    }

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}