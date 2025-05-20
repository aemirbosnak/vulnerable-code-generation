//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int arr[], int size, int key) {
    int start = 0, end = size - 1, mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[SIZE], key, index;

    printf("Enter %d integers: ", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &key);

    index = binarySearch(arr, SIZE, key);

    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found\n");
    }

    printArray(arr, SIZE);

    return 0;
}