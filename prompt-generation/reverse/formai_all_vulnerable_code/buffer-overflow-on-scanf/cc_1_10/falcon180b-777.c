//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000
#define MAX_VALUE 100000

typedef struct {
    int *data;
    int size;
} Bucket;

void createBuckets(Bucket *buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].data = (int *)malloc(MAX_SIZE * sizeof(int));
        buckets[i].size = 0;
    }
}

void destroyBuckets(Bucket *buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i].data);
    }
}

void insertElement(Bucket *bucket, int element) {
    if (bucket->size == MAX_SIZE) {
        printf("Bucket is full!\n");
        return;
    }
    bucket->data[bucket->size++] = element;
}

void bucketSort(int *array, int size, int numBuckets) {
    Bucket *buckets = (Bucket *)malloc(numBuckets * sizeof(Bucket));
    createBuckets(buckets, numBuckets);

    int range = MAX_VALUE / numBuckets;
    int remainder = MAX_VALUE % numBuckets;

    for (int i = 0; i < size; i++) {
        int bucketIndex = array[i] / range;
        if (array[i] % range == 0 && i == size - 1) {
            bucketIndex++;
        }
        insertElement(buckets[bucketIndex].data, array[i]);
    }

    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            array[index++] = buckets[i].data[j];
        }
    }

    destroyBuckets(buckets, numBuckets);
    free(buckets);
}

int main() {
    srand(time(0));

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % MAX_VALUE;
    }

    int numBuckets;
    printf("Enter the number of buckets: ");
    scanf("%d", &numBuckets);

    bucketSort(array, size, numBuckets);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}