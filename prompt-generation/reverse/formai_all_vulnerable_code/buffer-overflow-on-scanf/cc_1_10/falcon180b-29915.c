//Falcon-180B DATASET v1.0 Category: Sorting ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Pair;

void swap(Pair* arr, int i, int j) {
    Pair temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(Pair* arr, int low, int high) {
    int pivot_index = rand() % (high - low + 1) + low;
    swap(arr, pivot_index, high);
    return partition_helper(arr, low, high);
}

int partition_helper(Pair* arr, int low, int high) {
    int pivot_value = arr[high].data;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot_value) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

void quick_sort(Pair* arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

void print_array(Pair* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d (%d)\n", arr[i].data, arr[i].index);
    }
}

int main() {
    srand(time(NULL));
    Pair arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array (<= %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i].data);
        arr[i].index = i;
    }

    quick_sort(arr, 0, size - 1);

    printf("Sorted array:\n");
    print_array(arr, size);

    return 0;
}