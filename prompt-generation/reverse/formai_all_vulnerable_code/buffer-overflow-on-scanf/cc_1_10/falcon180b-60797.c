//Falcon-180B DATASET v1.0 Category: Sorting ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int arr[], int low, int high) {
    int i = low, j = high;
    int pivot = arr[(low + high) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }

    if (low < j)
        quick_sort(arr, low, j);
    if (i < high)
        quick_sort(arr, i, high);
}

int main() {
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[MAX_SIZE];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quick_sort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}