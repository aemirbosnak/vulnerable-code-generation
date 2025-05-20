//Falcon-180B DATASET v1.0 Category: Sorting ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Element;

void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Element arr[], int left, int right, int pivotIndex) {
    Element pivot = arr[pivotIndex];
    swap(&arr[pivotIndex], &arr[right]);

    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i].data <= pivot.data) {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(&arr[storeIndex], &arr[right]);
    return storeIndex;
}

void quickSort(Element arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = rand() % (right - left + 1) + left;
    int newPivotIndex = partition(arr, left, right, pivotIndex);

    quickSort(arr, left, newPivotIndex - 1);
    quickSort(arr, newPivotIndex + 1, right);
}

void printArray(Element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    srand(time(0));

    Element arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    quickSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}