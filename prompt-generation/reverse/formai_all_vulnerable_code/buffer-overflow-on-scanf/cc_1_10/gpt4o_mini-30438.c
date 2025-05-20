//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>

// Interpolation Search Function
int interpolationSearch(int arr[], int size, int x) {
    int low = 0, high = (size - 1);
    
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        // Estimate the position of x
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (x - arr[low]));
        
        // Check if x is present at pos
        if (arr[pos] == x) {
            return pos;
        }
        
        // If x is greater, ignore left half
        if (arr[pos] < x) {
            low = pos + 1;
        }
        // If x is smaller, ignore right half
        else {
            high = pos - 1;
        }
    }
    return -1; // x is not present in array
}

// Function to create an array and sort it
void createAndSortArray(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Simple bubble sort to arrange elements in ascending order
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Main Function
int main() {
    int size;

    printf("Enter the size of the array: ");
    while (1) {
        scanf("%d", &size);
        if (size > 0) break; // Ensure size is positive
        printf("Size of array must be a positive integer. Please re-enter: ");
    }

    int arr[size];

    createAndSortArray(arr, size);

    int x;
    printf("Enter the number to search: ");
    scanf("%d", &x);

    int result = interpolationSearch(arr, size, x);
    
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}