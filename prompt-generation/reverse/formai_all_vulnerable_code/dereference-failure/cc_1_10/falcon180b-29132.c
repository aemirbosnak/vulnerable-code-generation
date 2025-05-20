//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100000

typedef struct {
    int *array;
    int size;
} Bucket;

void createBucket(Bucket *bucket, int size) {
    bucket->array = (int *)malloc(size * sizeof(int));
    bucket->size = size;
}

void freeBucket(Bucket *bucket) {
    free(bucket->array);
}

void insert(Bucket *bucket, int value) {
    int i = 0;
    while (i < bucket->size && bucket->array[i] < value) {
        i++;
    }
    bucket->array[i] = value;
}

void sort(Bucket *buckets, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (buckets[i].array[j]!= -1) {
                printf("%d ", buckets[i].array[j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int i, j, k, n;
    Bucket *buckets;
    srand(time(NULL));
    n = rand() % 10 + 1;
    buckets = (Bucket *)malloc(n * sizeof(Bucket));
    for (i = 0; i < n; i++) {
        createBucket(&buckets[i], MAX_SIZE);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < rand() % MAX_SIZE; j++) {
            k = rand() % MAX_SIZE;
            while (k == -1) {
                k = rand() % MAX_SIZE;
            }
            insert(&buckets[i], k);
        }
    }
    sort(buckets, n);
    for (i = 0; i < n; i++) {
        freeBucket(&buckets[i]);
    }
    free(buckets);
    return 0;
}