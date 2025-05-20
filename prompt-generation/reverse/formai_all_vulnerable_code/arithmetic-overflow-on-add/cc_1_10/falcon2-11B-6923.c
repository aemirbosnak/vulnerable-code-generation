//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucket_sort(int arr[], int n) {
    int buckets[MAX_BUCKETS];
    int *buckets_ptr = &buckets[0];
    int *end_ptr = &buckets[MAX_BUCKETS];
    int i, j, k, pos;
    int min_val, max_val;

    for (i = 0; i < n; i++) {
        buckets_ptr[i % MAX_BUCKETS]++;
    }

    for (i = 1; i < MAX_BUCKETS; i++) {
        buckets_ptr[i] += buckets_ptr[i - 1];
    }

    min_val = arr[0];
    max_val = arr[0];

    for (i = 0; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }

        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    for (i = 0; i < n; i++) {
        pos = (int) (arr[i] - min_val) / (max_val - min_val);
        pos = pos % MAX_BUCKETS;
        arr[i] = pos;
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 2, 1, 4, 7, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("After Sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}