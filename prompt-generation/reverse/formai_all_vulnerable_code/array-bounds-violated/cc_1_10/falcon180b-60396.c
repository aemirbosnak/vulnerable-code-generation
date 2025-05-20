//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int size;

void insert(int val) {
    if (size == MAX_SIZE) {
        printf("Array is full\n");
        return;
    }

    arr[size++] = val;
}

void display() {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int val) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == val) {
            return mid;
        }

        if (arr[mid] < val) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search:\n");
    int val;
    scanf("%d", &val);

    int l_index = linearSearch(val);
    int b_index = binarySearch(val);

    if (l_index == -1) {
        printf("Element not found in the array\n");
    } else {
        printf("Element found at index %d\n", l_index);
    }

    if (b_index == -1) {
        printf("Element not found in the array\n");
    } else {
        printf("Element found at index %d\n", b_index);
    }

    return 0;
}