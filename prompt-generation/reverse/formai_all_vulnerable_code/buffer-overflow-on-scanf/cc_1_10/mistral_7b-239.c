//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int linearSearch(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x)
            return i;
    }

    return -1;
}

int ternarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == x)
            return mid1;

        if (arr[mid1] < x) {
            if (arr[mid2] > x)
                left = mid2 + 1;

            else
                return ternarySearch(arr, mid1 + 1, mid2, x);
        }

        else {
            if (arr[mid2] < x)
                right = mid1 - 1;

            else
                return ternarySearch(arr, left, mid1 - 1, x);
        }
    }

    return -1;
}

int interpolationSearch(int arr[], int size, int x) {
    int low = 0, high = size - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        int pos = low + ((x - arr[low]) * (high - low) / (arr[high] - arr[low]));

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            low = pos + 1;

        else
            high = pos - 1;
    }

    return -1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size, key, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    printf("Choose the search algorithm:\n");
    printf("1. Binary Search\n");
    printf("2. Linear Search\n");
    printf("3. Ternary Search\n");
    printf("4. Interpolation Search\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Position of %d using Binary Search: %d\n", key, binarySearch(arr, 0, size - 1, key));
            break;
        case 2:
            printf("Position of %d using Linear Search: %d\n", key, linearSearch(arr, size, key));
            break;
        case 3:
            printf("Position of %d using Ternary Search: %d\n", key, ternarySearch(arr, 0, size - 1, key));
            break;
        case 4:
            printf("Position of %d using Interpolation Search: %d\n", key, interpolationSearch(arr, size, key));
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    printf("Array: ");
    printArray(arr, size);

    return 0;
}