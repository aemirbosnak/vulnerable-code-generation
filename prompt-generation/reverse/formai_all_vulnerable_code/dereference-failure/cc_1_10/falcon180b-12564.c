//Falcon-180B DATASET v1.0 Category: Sorting ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void quick_sort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        quick_sort(arr, left, j);
    }
    if (i < right) {
        quick_sort(arr, i, right);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int r = rand() % size;
        int t = arr[i];
        arr[i] = arr[r];
        arr[r] = t;
    }
    quick_sort(arr, 0, size - 1);
    printf("Sorted array:\n");
    print_array(arr, size);
    return 0;
}