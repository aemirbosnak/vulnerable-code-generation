//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: excited
// Searching algorithm example program in a excited style

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to search an element in a sorted array
int search(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[MAX], n, key, result;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the sorted array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = search(arr, n, key);

    if (result == -1) {
        printf("Element not found!");
    } else {
        printf("Element found at index %d", result);
    }

    return 0;
}