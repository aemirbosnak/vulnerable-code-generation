//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = arr[(left + right) / 2];
    int i = left - 1;
    int j = right + 1;
    while (i < j) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    quicksort(arr, left, j);
    quicksort(arr, j + 1, right);
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);

    int arr[n];
    srand(time(NULL));
    for(i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    clock_t start = clock();
    quicksort(arr, 0, n - 1);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %f seconds\n", time_taken);
    return 0;
}