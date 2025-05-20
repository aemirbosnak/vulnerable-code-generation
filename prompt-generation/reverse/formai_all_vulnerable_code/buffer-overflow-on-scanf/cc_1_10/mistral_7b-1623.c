//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(type, a, b) do { type t = (a); (a) = (b); (b) = t; } while(0)

typedef struct {
    int key;
    char element[10];
} Item;

void printArray(Item arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s\t%d\n", arr[i].element, arr[i].key);
    }
}

void insertionSort(Item arr[], int size, int gap) {
    int i, j, key;
    Item temp;

    for (i = gap; i < size; i++) {
        key = arr[i].key;
        j = i;

        while (j >= gap && arr[j - gap].key > key) {
            arr[j].key = arr[j - gap].key;
            j -= gap;
        }

        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}

void knuthSort(Item arr[], int size) {
    int i, gap;

    for (gap = size / 2; gap > 0; gap /= 2) {
        for (i = gap; i < size; i += 1 + (i > gap ? gap : 0)) {
            insertionSort(arr, size, gap);
        }
    }
}

int main() {
    int n, i;
    Item arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s%d", arr[i].element, &arr[i].key);
    }

    printf("\nUnsorted array:\n");
    printArray(arr, n);

    knuthSort(arr, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}