//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to hold elements and their access frequency
typedef struct {
    int value;
    int frequency;
} Element;

// Function to perform adaptive binary search
int adaptiveBinarySearch(Element arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the target is present at mid
        if (arr[mid].value == target) {
            // Increase frequency whenever the element is found
            arr[mid].frequency++;
            return mid;
        }

        // If the target is smaller than the mid value
        if (target < arr[mid].value) {
            high = mid - 1;
        } else { // If the target is larger than the mid value
            low = mid + 1;
        }
    }

    return -1; // Target not present
}

// Function to print the array with frequencies
void printArray(Element arr[], int size) {
    printf("Elements and their access frequencies:\n");
    for (int i = 0; i < size; i++) {
        printf("Value: %d, Frequency: %d\n", arr[i].value, arr[i].frequency);
    }
}

int main() {
    Element arr[MAX_SIZE];
    int n, target, result;

    // Initialize the access frequency to zero
    printf("Enter the number of elements in the sorted array (max 100): ");
    scanf("%d", &n);
    
    if(n > MAX_SIZE || n <= 0) {
        printf("Invalid number of elements. Must be between 1 and 100.\n");
        return 1;
    }

    printf("Enter the sorted elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].frequency = 0; // Initialize frequency to 0
    }

    printf("Enter the target value to search: ");
    scanf("%d", &target);

    result = adaptiveBinarySearch(arr, n, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found.\n");
    }

    // Print the elements and their frequencies after the search
    printArray(arr, n);

    return 0;
}