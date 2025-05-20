//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

void ternary_search(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r + (r - l) / 3;

        // Checking if x is present at mid1
        if (arr[mid1] == x) {
            printf("Element found at index %d.\n", mid1);
            return;
        }

        // If x is smaller, it can only be present in left subarray
        if (x < arr[mid1]) {
            r = mid1 - 1;
        }

        // Else the element can only be present in right subarray
        else {
            l = mid1 + 1;
        }

        // Repeat the process
        ternary_search(arr, l, r, x);
    }

    // Element is not present in array
    else {
        printf("Element not present in array.\n");
    }
}

int main() {
    int arr[SIZE], i, x;

    printf("Enter %d elements:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search:\n");
    scanf("%d", &x);

    ternary_search(arr, 0, SIZE - 1, x);

    return 0;
}