//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 10
#define MAX_SIZE 100000

void print_array(int arr[], int size) {
    int i;
    printf("[");
    for (i = 0; i < size; i++) {
        if (i > 0)
            printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");
}

int binary_search(int arr[], int size, int value) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value)
            return mid;

        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int linear_search(int arr[], int size, int value) {
    int i;

    for (i = 0; i < size; i++) {
        if (arr[i] == value)
            return i;
    }

    return -1;
}

int search(int arr[], int size, int value) {
    int result;

    if (size > MAX_SIZE / 2) {
        result = binary_search(arr, size, value);
        if (result == -1)
            result = linear_search(arr, size, value);
    } else {
        result = linear_search(arr, size, value);
    }

    return result;
}

int main() {
    int arr[MIN_SIZE], i, value;

    printf("Enter %d integers:\n", MIN_SIZE);
    for (i = 0; i < MIN_SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to search for:\n");
    scanf("%d", &value);

    int index = search(arr, MIN_SIZE, value);

    if (index == -1)
        printf("Value not found.\n");
    else {
        printf("Value found at index %d.\n", index);
        printf("Array before index %d:\n", index);
        print_array(arr, index);
    }

    return 0;
}