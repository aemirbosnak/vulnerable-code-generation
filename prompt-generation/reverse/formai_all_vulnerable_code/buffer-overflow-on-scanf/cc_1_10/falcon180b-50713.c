//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Element;

void swap(Element* a, Element* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

int partition(Element* arr, int low, int high) {
    int pivot_index = rand() % (high - low + 1) + low;
    swap(&arr[pivot_index], &arr[high]);
    int pivot_value = arr[high].data;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].data <= pivot_value) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(Element* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void print_array(Element* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Element arr[MAX_SIZE];
    int size = 0;

    while (size < MAX_SIZE) {
        int data;
        printf("Enter a number: ");
        scanf("%d", &data);
        arr[size].data = data;
        arr[size].index = size;
        size++;
    }

    quick_sort(arr, 0, size - 1);
    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}