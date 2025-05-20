//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to perform binary search using buddy system
int buddySearch(int arr[], int l, int r, int key) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        // Check if key is present at mid
        if (arr[mid] == key)
            return mid;

        // If arr[mid] is greater than key, then key can only be present in left subarray
        if (arr[mid] > key) {
            r = mid - 1;
        }

        // If arr[mid] is smaller than key, then key can only be present in right subarray
        else {
            int buddy = mid + (mid & 1); // Find buddy index

            // If key is not present at mid and buddy, then array is not sorted
            if (arr[buddy] != key)
                swap(&arr[mid], &arr[buddy]);

            l = mid + 1;
        }
    }

    // If we reach here, then key is not present
    return -1;
}

int main() {
    int arr[MAX_SIZE], i, key, n;

    printf("Enter the number of elements to be entered in the array: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    int result = buddySearch(arr, 0, n - 1, key);

    if (result == -1)
        printf("Key %d not present in array\n", key);
    else
        printf("Key %d found at index %d\n", key, result);

    return 0;
}