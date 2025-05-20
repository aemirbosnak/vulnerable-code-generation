//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000000
#define MAX_VALUE 1000000

typedef struct {
    int *array;
    int size;
} Bucket;

void createBucket(Bucket *bucket, int size) {
    bucket->array = (int *)malloc(size * sizeof(int));
    bucket->size = size;
    memset(bucket->array, 0, size * sizeof(int));
}

void destroyBucket(Bucket *bucket) {
    free(bucket->array);
}

void insertElement(Bucket *bucket, int value) {
    int index = value / bucket->size;
    bucket->array[index]++;
}

void sortBucket(Bucket *bucket) {
    int i, j, temp;
    for (i = 0; i < bucket->size - 1; i++) {
        for (j = 0; j < bucket->array[i]; j++) {
            temp = bucket->array[i];
            bucket->array[i] = bucket->array[i + 1];
            bucket->array[i + 1] = temp;
            i++;
        }
    }
}

void bucketSort(int *array, int size) {
    Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
    createBucket(bucket, size);

    int i;
    for (i = 0; i < size; i++) {
        insertElement(bucket, array[i]);
    }

    sortBucket(bucket);

    int index = 0;
    for (i = 0; i < bucket->size; i++) {
        while (bucket->array[i] > 0) {
            array[index++] = i * bucket->size;
            bucket->array[i]--;
        }
    }

    destroyBucket(bucket);
}

int main() {
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array = (int *)malloc(size * sizeof(int));

    srand(time(NULL));
    for (i = 0; i < size; i++) {
        array[i] = rand() % MAX_VALUE;
    }

    printf("Before sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    bucketSort(array, size);

    printf("\nAfter sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}