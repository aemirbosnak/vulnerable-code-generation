//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, i, j, k, found = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    int x;
    scanf("%d", &x);

    // Linear search
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            found = 1;
            break;
        }
    }

    // Binary search
    if (!found) {
        // Sort the array in ascending order
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        // Perform binary search
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                found = 1;
                break;
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    if (found) {
        printf("Element found at index %d\n", i);
    } else {
        printf("Element not found\n");
    }

    return 0;
}