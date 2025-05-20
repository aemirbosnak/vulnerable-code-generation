//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct bucket {
    int* arr;
    int size;
} Bucket;

Bucket* createBucket(int size) {
    Bucket* bucket = malloc(sizeof(Bucket));
    bucket->arr = malloc(size * sizeof(int));
    bucket->size = size;
    return bucket;
}

void destroyBucket(Bucket* bucket) {
    free(bucket->arr);
    free(bucket);
}

void insertElement(Bucket* bucket, int element) {
    int* arr = bucket->arr;
    int i;
    for (i = 0; i < bucket->size; i++) {
        if (arr[i] == 0) {
            arr[i] = element;
            return;
        }
    }
    bucket->size++;
    arr = realloc(bucket->arr, bucket->size * sizeof(int));
    if (!arr) {
        printf("Memory allocation error\n");
        exit(1);
    }
    arr[i] = element;
}

int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    Bucket* buckets = createBucket(n);
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        insertElement(buckets, element);
    }
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", buckets->arr[i]);
    }
    destroyBucket(buckets);
    return 0;
}