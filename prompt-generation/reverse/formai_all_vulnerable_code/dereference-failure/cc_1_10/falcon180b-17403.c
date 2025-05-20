//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucket_sort(int *arr, int n) {
    int i, j, max_val = arr[0];
    int *bucket = (int *)malloc(n * sizeof(int));

    // Find the maximum element in the array
    for (i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Allocate memory for the buckets
    for (i = 0; i < max_val + 1; i++) {
        bucket[i] = 0;
    }

    // Place each element in its corresponding bucket
    for (i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    // Concatenate the buckets to form the sorted array
    int k = 0;
    for (i = 0; i < max_val + 1; i++) {
        for (j = 0; j < bucket[i]; j++) {
            arr[k++] = i;
        }
    }

    free(bucket);
}

void print_array(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    // Generate random array of integers
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Original array:\n");
    print_array(arr, n);

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    free(arr);
    return 0;
}