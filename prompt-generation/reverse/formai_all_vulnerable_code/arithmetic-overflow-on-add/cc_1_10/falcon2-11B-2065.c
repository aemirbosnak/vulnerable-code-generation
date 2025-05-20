//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int key;
    int value;
} Bucket;

void swap(Bucket* a, Bucket* b) {
    Bucket temp = *a;
    *a = *b;
    *b = temp;
}

void sort_buckets(Bucket* bucket_arr, int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (bucket_arr[j].key < bucket_arr[min_idx].key) {
                min_idx = j;
            }
        }
        swap(&bucket_arr[i], &bucket_arr[min_idx]);
    }
}

void bucket_sort(int* arr, int n) {
    int buckets[n + 1];
    Bucket* bucket_arr = (Bucket*) malloc(n * sizeof(Bucket));
    for (int i = 0; i < n; i++) {
        int bucket_idx = (int) ceil((arr[i] - arr[0]) / (arr[n - 1] - arr[0]));
        if (bucket_idx < 0 || bucket_idx > n) {
            bucket_idx = 0;
        }
        bucket_arr[bucket_idx].key = arr[i];
        bucket_arr[bucket_idx].value = i;
        buckets[bucket_idx]++;
    }
    for (int i = 0; i < n; i++) {
        int bucket_idx = (int) ceil((arr[i] - arr[0]) / (arr[n - 1] - arr[0]));
        if (bucket_idx < 0 || bucket_idx > n) {
            bucket_idx = 0;
        }
        for (int j = 0; j < buckets[bucket_idx]; j++) {
            arr[j + i] = bucket_arr[bucket_idx].key;
        }
    }
    free(bucket_arr);
}

int main() {
    int arr[] = {9, 4, 2, 7, 1, 6, 3, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucket_sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}