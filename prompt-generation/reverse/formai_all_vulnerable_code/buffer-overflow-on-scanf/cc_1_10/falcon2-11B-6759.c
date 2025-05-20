//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int max(int a, int b) {
    return (a > b)? a : b;
}

void min_heapify(int *arr, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < size && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest!= i) {
        int tmp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = tmp;

        min_heapify(arr, size, smallest);
    }
}

void build_min_heap(int *arr, int size) {
    for (int i = size / 2; i >= 0; i--) {
        min_heapify(arr, size, i);
    }
}

void heap_sort(int *arr, int size) {
    build_min_heap(arr, size);

    for (int i = size - 1; i >= 0; i--) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;

        min_heapify(arr, i, 0);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int*)malloc(size * sizeof(int));

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    print_array(arr, size);

    build_min_heap(arr, size);

    printf("Sorted array: ");
    print_array(arr, size);

    free(arr);

    return 0;
}