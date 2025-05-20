//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10
#define NUM_BUCKETS 10

typedef struct Bucket {
    int *arr;
    int used;
    int capacity;
} Bucket;

typedef struct BucketSort {
    Bucket buckets[NUM_BUCKETS];
    int max;
    int min;
} BucketSort;

BucketSort *create_bucket_sort(int max, int min) {
    BucketSort *bs = malloc(sizeof(BucketSort));

    for (int i = 0; i < NUM_BUCKETS; i++) {
        bs->buckets[i].arr = malloc(sizeof(int) * BUCKET_SIZE);
        bs->buckets[i].used = 0;
        bs->buckets[i].capacity = BUCKET_SIZE;
    }

    bs->max = max;
    bs->min = min;

    return bs;
}

void destroy_bucket_sort(BucketSort *bs) {
    for (int i = 0; i < NUM_BUCKETS; i++) {
        free(bs->buckets[i].arr);
    }

    free(bs);
}

void insert(BucketSort *bs, int value) {
    int bucket_index = (value - bs->min) / (bs->max - bs->min) * NUM_BUCKETS;

    if (bs->buckets[bucket_index].used == bs->buckets[bucket_index].capacity) {
        // Double the capacity of the bucket
        int *new_arr = malloc(sizeof(int) * bs->buckets[bucket_index].capacity * 2);
        for (int i = 0; i < bs->buckets[bucket_index].used; i++) {
            new_arr[i] = bs->buckets[bucket_index].arr[i];
        }
        free(bs->buckets[bucket_index].arr);
        bs->buckets[bucket_index].arr = new_arr;
        bs->buckets[bucket_index].capacity *= 2;
    }

    bs->buckets[bucket_index].arr[bs->buckets[bucket_index].used++] = value;
}

int *sort(BucketSort *bs) {
    int *sorted = malloc(sizeof(int) * NUM_BUCKETS * BUCKET_SIZE);
    int index = 0;

    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < bs->buckets[i].used; j++) {
            sorted[index++] = bs->buckets[i].arr[j];
        }
    }

    return sorted;
}

int main() {
    int n;
    scanf("%d", &n);

    int max = -2147483648, min = 2147483647;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        if (value > max) {
            max = value;
        }
        if (value < min) {
            min = value;
        }
    }

    BucketSort *bs = create_bucket_sort(max, min);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insert(bs, value);
    }

    int *sorted = sort(bs);

    for (int i = 0; i < n; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    destroy_bucket_sort(bs);
    free(sorted);

    return 0;
}