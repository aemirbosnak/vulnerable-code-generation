//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1; // Element not found
}

// Function to perform binary search
int binarySearch(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Element not found
}

int main() {
    int arr[100], n, x;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    // Perform linear search
    int result = linearSearch(arr, n, x);
    if (result == -1)
        printf("Element not found in array.\n");
    else
        printf("Element found at position %d.\n", result);

    // Perform binary search
    result = binarySearch(arr, n, x);
    if (result == -1)
        printf("Element not found in array.\n");
    else
        printf("Element found at position %d.\n", result);

    return 0;
}