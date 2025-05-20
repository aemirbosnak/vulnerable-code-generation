//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];
int n;

void binary_search(int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            printf("Element found at index %d\n", mid);
            return;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("Element not found\n");
}

void linear_search(int target) {
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("Element found at index %d\n", i);
            return;
        }
    }

    printf("Element not found\n");
}

int main() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);

    printf("Binary search:\n");
    binary_search(target);

    printf("\nLinear search:\n");
    linear_search(target);

    return 0;
}