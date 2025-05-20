//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Element;

void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(Element *arr, int size) {
    for (int i = 1; i < size; i++) {
        Element key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].data > key.data) {
            swap(&arr[j], &arr[j + 1]);
            j--;
        }

        arr[j + 1] = key;
    }
}

void binarySearch(Element *arr, int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].data == target) {
            printf("Element found at index %d\n", mid);
            return;
        }

        if (arr[mid].data < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("Element not found\n");
}

int main() {
    Element arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    insertionSort(arr, size);
    binarySearch(arr, size, 5);

    return 0;
}