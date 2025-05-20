//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void bucket_sort(int arr[], int n) {
    int i, j, count[MAX_SIZE] = {0};
    int *temp_arr = (int *) malloc(n * sizeof(int));
    if (temp_arr == NULL) {
        printf("Memory Error\n");
        exit(0);
    }
    for (i = 0; i < n; i++) {
        count[(arr[i] / (MAX_SIZE / n))]++;
    }
    for (i = 1; i < n; i++) {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        temp_arr[count[i] - 1] = arr[i];
        count[i]--;
    }
    for (i = 0; i < n; i++) {
        arr[i] = temp_arr[i];
    }
    free(temp_arr);
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
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

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start_time = clock();
    quick_sort(arr, 0, n - 1);
    clock_t end_time = clock();
    double elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %.6f seconds\n", elapsed_time);
    return 0;
}