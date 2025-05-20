//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Bucket {
    int *array;
    int size;
} Bucket;

void initializeBucket(Bucket *bucket) {
    bucket->array = (int *)malloc(MAX_SIZE * sizeof(int));
    bucket->size = 0;
}

void insertIntoBucket(Bucket *bucket, int value) {
    bucket->array[bucket->size++] = value;
}

void sortBucket(Bucket *bucket) {
    for (int i = 0; i < bucket->size - 1; i++) {
        for (int j = 0; j < bucket->size - i - 1; j++) {
            if (bucket->array[j] > bucket->array[j + 1]) {
                int temp = bucket->array[j];
                bucket->array[j] = bucket->array[j + 1];
                bucket->array[j + 1] = temp;
            }
        }
    }
}

void bucketSort(int *array, int n) {
    if (n <= 0) return;
    
    // Step 1: Create buckets
    Bucket *buckets = (Bucket *)malloc(n * sizeof(Bucket));
    for (int i = 0; i < n; i++) {
        initializeBucket(&buckets[i]);
    }

    // Step 2: Distribute input array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = array[i] * n / (MAX_SIZE + 1); // simple hashing
        insertIntoBucket(&buckets[index], array[i]);
    }

    // Step 3: Sort individual buckets and concatenate
    int outputIndex = 0;
    for (int i = 0; i < n; i++) {
        sortBucket(&buckets[i]);
        for (int j = 0; j < buckets[i].size; j++) {
            array[outputIndex++] = buckets[i].array[j];
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(buckets[i].array);
    }
    free(buckets);
}

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    int *array;

    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);
    
    array = (int *)malloc(n * sizeof(int));
    
    printf("Enter %d elements (0 to %d):\n", n, MAX_SIZE);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Original array:\n");
    printArray(array, n);
    
    bucketSort(array, n);
    
    printf("Sorted array:\n");
    printArray(array, n);
    
    free(array);
    return 0;
}