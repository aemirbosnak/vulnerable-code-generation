//Falcon-180B DATASET v1.0 Category: Sorting ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_VALUE 1000

typedef struct {
    int data;
    int index;
} element_t;

void swap(element_t* a, element_t* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

int partition(element_t* arr, int low, int high) {
    element_t pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data <= pivot.data) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(element_t* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(element_t* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    element_t arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array (<= %d): ", MAX_SIZE);
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