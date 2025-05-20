//Falcon-180B DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} element;

void swap(element *a, element *b) {
    element tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(element arr[], int low, int high) {
    int pivot = arr[(low + high) / 2].data;
    swap(&arr[high], &arr[(low + high) / 2]);
    int store_index = low;
    for (int i = low; i < high; i++) {
        if (arr[i].data <= pivot) {
            swap(&arr[i], &arr[store_index]);
            store_index++;
        }
    }
    swap(&arr[store_index], &arr[high]);
    return store_index;
}

void quick_sort(element arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void print_array(element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    element arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        arr[i].data = rand() % 100;
        arr[i].index = i;
    }

    quick_sort(arr, 0, size - 1);

    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}