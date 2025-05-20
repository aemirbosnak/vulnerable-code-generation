//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];
int n;

void initArray(int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    n = size;
}

void printArray() {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void binarySearch(int target) {
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            printf("Found %d at index %d\n", target, mid);
            return;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    printf("Not found\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size > MAX_SIZE) {
        printf("Error: Array size cannot exceed %d\n", MAX_SIZE);
        return 1;
    }
    initArray(size);
    int target;
    printf("Enter the target number to search for: ");
    scanf("%d", &target);
    binarySearch(target);
    return 0;
}