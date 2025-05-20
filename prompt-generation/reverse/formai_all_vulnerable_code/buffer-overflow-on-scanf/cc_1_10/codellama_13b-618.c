//Code Llama-13B DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_SIZE 100
#define MAX_KEY_LENGTH 100

int linear_search(int arr[], int key, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int key, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] > key) {
            return binary_search(arr, key, low, mid - 1);
        }
        return binary_search(arr, key, mid + 1, high);
    }
    return -1;
}

int main() {
    int arr[MAX_ARRAY_SIZE];
    int n, key, low, high;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;

    int result = linear_search(arr, key, n);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    result = binary_search(arr, key, low, high);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}