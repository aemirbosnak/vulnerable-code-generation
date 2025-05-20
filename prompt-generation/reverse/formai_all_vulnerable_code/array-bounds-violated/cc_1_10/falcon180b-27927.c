//Falcon-180B DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int data;
    int index;
} Element;

void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Element* arr, int low, int high) {
    int pivot = arr[high].data;
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

void quickSort(Element* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(Element* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Element arr[MAX_SIZE];
    int size = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        int data = rand() % MAX_SIZE;
        if (size == MAX_SIZE || data!= arr[size - 1].data) {
            arr[size].data = data;
            arr[size].index = size;
            size++;
        }
    }

    quickSort(arr, 0, size - 1);
    printArray(arr, size);

    return 0;
}