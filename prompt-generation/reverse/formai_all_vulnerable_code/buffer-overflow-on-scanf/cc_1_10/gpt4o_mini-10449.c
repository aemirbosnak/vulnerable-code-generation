//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to perform Binary Search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }

    // Target was not found
    return -1;
}

// Function to perform Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

// Function to sort the array using Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
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

// Main function demonstrating the use of search algorithms
int main() {
    int arr[MAX_SIZE];
    int n, target;
    
    // Input the number of elements in the array
    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    // Input elements in the array
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array for binary search
    bubbleSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);

    // Input the target value to search
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    // Perform Binary Search
    int binaryResult = binarySearch(arr, 0, n - 1, target);
    if (binaryResult != -1) {
        printf("Binary Search: Element found at index %d.\n", binaryResult);
    } else {
        printf("Binary Search: Element not found.\n");
    }

    // Perform Linear Search
    int linearResult = linearSearch(arr, n, target);
    if (linearResult != -1) {
        printf("Linear Search: Element found at index %d.\n", linearResult);
    } else {
        printf("Linear Search: Element not found.\n");
    }

    // Demonstrating the efficiency of the algorithms
    printf("\nPerformance analysis:\n");
    printf("Binary Search: O(log n)\n");
    printf("Linear Search: O(n)\n");
    
    return 0;
}