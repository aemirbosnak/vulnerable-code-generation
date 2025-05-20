//Falcon-180B DATASET v1.0 Category: Sorting ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int *data;
    int size;
} Array;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    Array arr = {0};
    int size = 0;

    srand(time(NULL));

    for (int i = 0; i < MAX_SIZE; i++) {
        int num = rand() % 1000;
        if (size == 0 || num > arr.data[size - 1]) {
            arr.data = realloc(arr.data, (size + 1) * sizeof(int));
            arr.data[size] = num;
            size++;
        }
    }

    quick_sort(arr.data, 0, size - 1);

    printf("Sorted array:\n");
    print_array(arr.data, size);

    return 0;
}