//FormAI DATASET v1.0 Category: Searching algorithm ; Style: ultraprecise
#include <stdio.h>

int search(int arr[], int n, int key) {
    // Initialize variables
    int left = 0, right = n - 1;

    // loop through the array until there is no element left
    while (left <= right) {
        // Find the middle element of the array
        int mid = (left + right) / 2;

        if (arr[mid] == key) {
            // if the middle element is the key we are searching for, return its index
            return mid;
        } else if (arr[mid] < key) {
            // if the middle element is smaller than the key then search the right half of the array
            left = mid + 1;
        } else {
            // if the middle element is greater than the key then search the left half of the array
            right = mid - 1;
        }
    }

    // if the element is not present in the array return -1
    return -1;
}


// Main program
int main() {
    // Initialize arrays
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Get user input
    int key;
    printf("Enter the number to search: ");
    scanf("%d", &key);

    // Search for the number in the array
    int index = search(arr, n, key);

    // Print the result
    if (index == -1) {
        printf("%d not found in the array\n", key);
    } else {
        printf("%d found at index %d\n", key, index);
    }

    return 0;
}