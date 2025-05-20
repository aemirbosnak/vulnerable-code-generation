//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

int arr[MAX_SIZE];
int size;

void init(int n) {
    size = n;
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2;
    }
}

void print_array() {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linear_search(int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binary_search(int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    init(n);
    print_array();

    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = linear_search(key);

    if (result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at position %d.\n", result);
    }

    result = binary_search(key);

    if (result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at position %d.\n", result);
    }

    return 0;
}