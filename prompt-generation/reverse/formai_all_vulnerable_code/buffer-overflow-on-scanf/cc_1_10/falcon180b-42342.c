//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int key;
} node;

node arr[MAX_SIZE];

void insertionSort(int low, int high) {
    int i, j, key, temp;
    for (i = low + 1; i <= high; i++) {
        key = arr[i].key;
        j = i - 1;
        while (j >= low && arr[j].key > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = arr[i];
    }
}

int binarySearch(int low, int high, int key) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid].key == key)
            return mid;
        if (arr[mid].key > key)
            return binarySearch(low, mid - 1, key);
        return binarySearch(mid + 1, high, key);
    }
    return -1;
}

int main() {
    int n, i, key, position;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].key = arr[i].data;
    }
    insertionSort(0, n - 1);
    printf("Enter element to search: ");
    scanf("%d", &key);
    position = binarySearch(0, n - 1, key);
    if (position == -1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", position + 1);
    return 0;
}