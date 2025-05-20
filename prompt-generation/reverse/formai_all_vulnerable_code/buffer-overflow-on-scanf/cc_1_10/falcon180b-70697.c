//Falcon-180B DATASET v1.0 Category: Sorting ; Style: safe
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

int partition(Element arr[], int low, int high) {
    int pivot = arr[(low + high) / 2].data;
    Element temp = arr[(low + high) / 2];
    arr[(low + high) / 2] = arr[high];
    arr[high] = temp;

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(Element arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Array size cannot exceed %d\n", MAX_SIZE);
        return 0;
    }

    Element arr[MAX_SIZE];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        swap(arr + i, arr + j);
    }

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }

    quickSort(arr, 0, size - 1);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }

    return 0;
}