//FormAI DATASET v1.0 Category: Benchmarking ; Style: unmistakable
#include <stdio.h>
#include <time.h>

/* This program measures the time taken by different
   sorting algorithms to sort arrays of integers */

/* Bubble sort algorithm */
void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/* Selection sort algorithm */
void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;
    for(i = 0; i < n-1; i++) {
        min_idx = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

/* Insertion sort algorithm */
void insertion_sort(int arr[], int n) {
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[100000], n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    /* Measure time taken by Bubble Sort */
    clock_t start_time = clock();
    bubble_sort(arr, n);
    clock_t end_time = clock();
    double time_taken1 = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    /* Measure time taken by Selection Sort */
    start_time = clock();
    selection_sort(arr, n);
    end_time = clock();
    double time_taken2 = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    /* Measure time taken by Insertion Sort */
    start_time = clock();
    insertion_sort(arr, n);
    end_time = clock();
    double time_taken3 = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\nSorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken by Bubble Sort: %f seconds", time_taken1);
    printf("\nTime taken by Selection Sort: %f seconds", time_taken2);
    printf("\nTime taken by Insertion Sort: %f seconds", time_taken3);

    return 0;
}