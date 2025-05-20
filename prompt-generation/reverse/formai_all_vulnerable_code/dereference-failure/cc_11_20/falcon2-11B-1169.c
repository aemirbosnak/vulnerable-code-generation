//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10;
    int* arr = (int*)malloc(n * sizeof(int));
    int* sorted_arr = (int*)malloc(n * sizeof(int));

    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");

    int* buckets = (int*)malloc(n * sizeof(int));
    int* sorted_buckets = (int*)malloc(n * sizeof(int));
    int* bucket_sums = (int*)malloc(n * sizeof(int));
    int* bucket_counts = (int*)malloc(n * sizeof(int));

    int* sorted_idxs = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        buckets[i] = i;
        bucket_sums[i] = arr[i];
        bucket_counts[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        sorted_buckets[i] = -1;
        sorted_idxs[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (buckets[i] == buckets[j]) {
                bucket_counts[i]++;
                bucket_sums[i] += arr[j];
                if (sorted_buckets[j] == -1) {
                    sorted_buckets[j] = i;
                    sorted_idxs[j] = j;
                }
            }
        }
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (sorted_buckets[i]!= -1) {
            k++;
            for (int j = 0; j < bucket_counts[sorted_buckets[i]]; j++) {
                sorted_arr[k] = arr[sorted_idxs[i]];
                k++;
            }
        }
    }

    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");

    free(arr);
    free(sorted_arr);
    free(buckets);
    free(sorted_buckets);
    free(bucket_sums);
    free(bucket_counts);
    free(sorted_idxs);

    return 0;
}