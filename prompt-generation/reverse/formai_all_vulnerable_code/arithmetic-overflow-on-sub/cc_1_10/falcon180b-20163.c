//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    do {
        swapped = false;
        for (i = 1; i < n; i++) {
            if (arr[i-1] > arr[i]) {
                swap(&arr[i-1], &arr[i]);
                swapped = true;
            }
        }
    } while (swapped);
}

int binarySearch(int arr[], int target, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int n, target;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    bubbleSort(arr, n);

    int index = binarySearch(arr, target, 0, n-1);

    if (index == -1) {
        printf("Target element not found in the array.\n");
    } else {
        printf("Target element found at index %d.\n", index);
    }

    return 0;
}