//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE], n;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void binary_search(int arr[], int n, int target) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            printf("Element found at index %d\n", mid);
            return;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Element not found\n");
}

int main() {
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, n);
    int target;
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    binary_search(arr, n, target);
    return 0;
}