//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int data;
    int key;
} Record;

void swap(Record *a, Record *b) {
    Record temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Record arr[], int low, int high) {
    Record pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].key < pivot.key) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(Record arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(Record arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].key == key)
            return mid;
        else if (arr[mid].key < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void search(Record arr[], int n, int key) {
    int result = binarySearch(arr, 0, n - 1, key);

    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at position %d\n", result);
}

void main() {
    Record arr[MAX];
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].data);
        arr[i].key = arr[i].data;
    }

    printf("Enter key to search: ");
    scanf("%d", &key);

    quickSort(arr, 0, n - 1);

    search(arr, n, key);
}