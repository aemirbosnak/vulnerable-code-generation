//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n) {
    int i, j;
    bool swapped = true;

    while (swapped) {
        swapped = false;
        for (i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }
    }
}

int binary_search(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int n, target;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, n);

    printf("Enter the target integer to search for: ");
    scanf("%d", &target);

    int index = binary_search(arr, n, target);

    if (index == -1) {
        printf("The target integer (%d) is not found in the array.\n", target);
    } else {
        printf("The target integer (%d) is found at index %d.\n", target, index);
    }

    return 0;
}