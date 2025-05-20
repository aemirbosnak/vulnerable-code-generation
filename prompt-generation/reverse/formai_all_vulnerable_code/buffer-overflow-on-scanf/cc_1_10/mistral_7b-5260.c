//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 10
#define MAX_SIZE 1000000

void binary_jump_search(int arr[], int size, int key) {
    int step = size / 2, start = 0;

    if (size <= MIN_SIZE) {
        while (arr[start] != key && start < size - 1) {
            start++;
        }
        if (arr[start] == key)
            printf("Element found at index %d\n", start);
        else
            printf("Element not present in the array\n");
        return;
    }

    while (step * 2 <= size && arr[start + step] <= key) {
        start += step;
        step += step;
    }

    int end = start + step;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            return;
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    printf("Element not present in the array\n");
}

int main() {
    int size = 1 + (rand() % (MAX_SIZE - MIN_SIZE + 1)) + MIN_SIZE;
    int arr[size];
    int key;

    printf("Array size: %d\n", size);

    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    binary_jump_search(arr, size, key);

    return 0;
}