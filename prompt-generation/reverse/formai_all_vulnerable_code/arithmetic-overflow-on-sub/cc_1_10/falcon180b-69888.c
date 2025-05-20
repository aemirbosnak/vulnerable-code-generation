//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, key, i, j;

    // Read the array from user
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the key from user
    printf("Enter the key to search: ");
    scanf("%d", &key);

    // Call the binary search function
    int result = binarySearch(arr, n, key);

    // Print the result
    if(result == -1) {
        printf("Key not found in the array.\n");
    }
    else {
        printf("Key found at position %d.\n", result);
    }

    return 0;
}

// Binary search function
int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n-1;
    int mid;

    while(left <= right) {
        mid = (left + right) / 2;

        if(arr[mid] == key) {
            return mid;
        }

        if(arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}