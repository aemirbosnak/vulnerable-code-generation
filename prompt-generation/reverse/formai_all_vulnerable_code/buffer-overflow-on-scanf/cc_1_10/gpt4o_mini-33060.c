//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define BUCKET_SIZE 10

typedef struct Bucket {
    int *arr;
    int size;
} Bucket;

void initializeBuckets(Bucket **buckets) {
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (Bucket *)malloc(sizeof(Bucket));
        buckets[i]->arr = (int *)malloc(MAX * sizeof(int));
        buckets[i]->size = 0;
    }
}

void insertIntoBucket(Bucket *buckets[], int num) {
    int index = num / BUCKET_SIZE;
    if (index >= BUCKET_SIZE) {
        index = BUCKET_SIZE - 1;
    }
    buckets[index]->arr[buckets[index]->size++] = num;
}

void sortBucket(Bucket *bucket) {
    for (int i = 0; i < bucket->size - 1; i++) {
        for (int j = 0; j < bucket->size - i - 1; j++) {
            if (bucket->arr[j] > bucket->arr[j + 1]) {
                int temp = bucket->arr[j];
                bucket->arr[j] = bucket->arr[j + 1];
                bucket->arr[j + 1] = temp;
            }
        }
    }
}

void bucketSort(int *array, int size) {
    Bucket *buckets[BUCKET_SIZE];
    initializeBuckets(buckets);

    for (int i = 0; i < size; i++) {
        insertIntoBucket(buckets, array[i]);
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        sortBucket(buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < buckets[i]->size; j++) {
            array[index++] = buckets[i]->arr[j];
        }
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]->arr);
        free(buckets[i]);
    }
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[MAX], n;

    printf("Enter the number of elements (max %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) {
        printf("The number of elements exceeds the maximum size allowed.\n");
        return 1;
    }

    printf("Enter %d elements (0-99): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        if (array[i] < 0 || array[i] > 99) {
            printf("Elements should be in the range 0-99.\n");
            return 1;
        }
    }

    printf("Original array:\n");
    printArray(array, n);

    bucketSort(array, n);

    printf("Sorted array:\n");
    printArray(array, n);

    return 0;
}