//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int min_element;
    int max_element;
    int *array;
    int size;
} bucket;

int main() {
    int n, i, j;
    int *arr;
    bucket *buckets;
    int bucket_size;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int*) malloc(n * sizeof(int));
    buckets = (bucket*) malloc(n * sizeof(bucket));
    bucket_size = n;

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        buckets[i].min_element = arr[i];
        buckets[i].max_element = arr[i];
        buckets[i].array = &arr[i];
        buckets[i].size = 1;
    }

    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (buckets[j].min_element > buckets[i].min_element) {
                buckets[j].min_element = buckets[i].min_element;
                buckets[j].max_element = buckets[i].max_element;
                buckets[j].array = buckets[i].array;
                buckets[j].size += buckets[i].size;
            }
        }
    }

    for (i = 0; i < n; i++) {
        printf("Element %d: %d\n", i, buckets[i].min_element);
    }

    free(arr);
    free(buckets);

    return 0;
}