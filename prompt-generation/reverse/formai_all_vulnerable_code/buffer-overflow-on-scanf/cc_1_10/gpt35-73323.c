//FormAI DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int paranoid_search(int arr[], int left, int right, int x) {
    if (left > right) return -1;

    int mid = (left + right) / 2;

    // check if x is the middle element
    if (x == arr[mid]) {
        printf("Target value found! Proceed with caution.\n");
        printf("Are you sure you want to proceed? (y/n)\n");

        // read user input and act accordingly
        char c = getchar();
        if (c == 'y' || c == 'Y') {
            printf("Opening door to the treasure...\n");
            return mid;
        } else {
            printf("Aborting mission...returning to safe location.\n");
            return -1;
        }
    }

    // if x is not the middle element, check left and right subarrays
    printf("Searching...\n");
    if (x < arr[mid]) {
        printf("Target value may be in the left subarray...\n");
        paranoid_search(arr, left, mid-1, x);
    } else {
        printf("Target value may be in the right subarray...\n");
        paranoid_search(arr, mid+1, right, x);
    }
}

int main() {
    int arr[] = {2, 5, 7, 10, 13, 15, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter target value to search for:\n");
    scanf("%d", &target);

    int result = paranoid_search(arr, 0, n-1, target);

    if (result == -1) {
        printf("Target value not found. Exiting program.\n");
    }

    return 0;
}