//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct bucket {
    int min_val;
    int max_val;
    int count;
    int *array;
} bucket;

int compare_func(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, i, j, k;
    int *arr;
    int *temp;
    bucket *buckets;
    int *min_arr;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of buckets: ");
    scanf("%d", &n);

    buckets = (bucket*)malloc(n * sizeof(bucket));
    for (i = 0; i < n; i++) {
        buckets[i].min_val = 0;
        buckets[i].max_val = n - 1;
        buckets[i].count = 0;
        buckets[i].array = (int*)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        int min_val = arr[i];
        int max_val = arr[i];
        int count = 0;

        for (j = i; j < n; j++) {
            if (arr[j] < min_val) {
                min_val = arr[j];
            }
            if (arr[j] > max_val) {
                max_val = arr[j];
            }
            count++;
        }

        buckets[i].min_val = min_val;
        buckets[i].max_val = max_val;
        buckets[i].count = count;
        buckets[i].array = (int*)malloc(count * sizeof(int));

        for (j = 0; j < count; j++) {
            buckets[i].array[j] = arr[j + i];
        }
    }

    qsort(buckets, n, sizeof(bucket), compare_func);

    for (i = 0; i < n; i++) {
        for (j = 0; j < buckets[i].count; j++) {
            arr[i + j] = buckets[i].array[j];
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    for (i = 0; i < n; i++) {
        free(buckets[i].array);
    }
    free(buckets);

    return 0;
}