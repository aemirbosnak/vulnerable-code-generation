//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int n;

// Function to perform binary search on the array
int binary_search(int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it lies in left subarray
        if (arr[mid] > x)
            return binary_search(low, mid - 1, x);

        // Else the element is in right subarray
        return binary_search(mid + 1, high, x);
    }

    // Element is not present in array
    return -1;
}

// Function to perform linear search on the array
int linear_search(int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// Function to sort the array in ascending order
void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Taking input from user
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting the array in ascending order
    bubble_sort(arr, n);

    // Performing linear search on the array
    int x;
    printf("Enter the element to search: ");
    scanf("%d", &x);
    int result = linear_search(x);
    if (result == -1)
        printf("\nElement not found!");
    else
        printf("\nElement found at position %d", result);

    // Performing binary search on the array
    printf("\nEnter the element to search: ");
    scanf("%d", &x);
    result = binary_search(0, n - 1, x);
    if (result == -1)
        printf("\nElement not found!");
    else
        printf("\nElement found at position %d", result);

    return 0;
}