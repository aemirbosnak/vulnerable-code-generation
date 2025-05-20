//FormAI DATASET v1.0 Category: Searching algorithm ; Style: careful
#include <stdio.h>

int linear_search(int arr[], int n, int x) {
    // function to perform linear search
    int i;
    for(i = 0; i < n; i++) {
        if(arr[i] == x) {
            return i; // element found, return index
        }
    }
    return -1; // element not found
}

int binary_search(int arr[], int l, int r, int x) {
    // function to perform binary search
    if(r >= l) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == x) {
            return mid; // element found, return index
        }
        if(arr[mid] > x) {
            return binary_search(arr, l, mid - 1, x); // search in left half
        }
        return binary_search(arr, mid + 1, r, x); // search in right half
    }
    return -1; // element not found
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements in the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter element to search: ");
    scanf("%d", &x);

    int choice;
    printf("Select search algorithm:\n1. Linear Search\n2. Binary Search\nEnter choice: ");
    scanf("%d", &choice);

    int index;
    if(choice == 1) {
        index = linear_search(arr, n, x);
    }
    else if(choice == 2) {
        index = binary_search(arr, 0, n - 1, x);
    }
    else {
        printf("Invalid choice!\n");
        return 0;
    }

    if(index >= 0) {
        printf("Element found at index %d\n", index);
    }
    else {
        printf("Element not found in array\n");
    }

    return 0;
}