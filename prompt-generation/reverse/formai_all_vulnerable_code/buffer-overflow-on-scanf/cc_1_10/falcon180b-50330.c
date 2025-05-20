//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

typedef struct {
    int value;
    int index;
} Bucket;

void createBuckets(Bucket* buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].value = i * MAX_RANGE / numBuckets;
        buckets[i].index = -1;
    }
}

void insertElement(Bucket* buckets, int numBuckets, int element) {
    int index = (element / MAX_RANGE) * numBuckets;
    int i = 0;
    while (i < numBuckets && buckets[i].value < element) {
        i++;
    }
    if (i == 0 || buckets[i - 1].value < element) {
        i = index;
    }
    if (buckets[i].index == -1) {
        buckets[i].index = 0;
    }
    buckets[i].value = element;
}

void sortBuckets(Bucket* buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        if (buckets[i].index!= -1) {
            int j = 0;
            while (j < buckets[i].index) {
                int temp = buckets[j].value;
                buckets[j].value = buckets[j + 1].value;
                buckets[j + 1].value = temp;
                j++;
            }
        }
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numElements, numBuckets = 10;
    int* arr = (int*)malloc(sizeof(int) * MAX_SIZE);
    Bucket* buckets = (Bucket*)malloc(sizeof(Bucket) * numBuckets);

    printf("Enter the number of elements: ");
    scanf("%d", &numElements);

    srand(time(NULL));
    for (int i = 0; i < numElements; i++) {
        arr[i] = rand() % MAX_RANGE;
    }

    createBuckets(buckets, numBuckets);

    for (int i = 0; i < numElements; i++) {
        insertElement(buckets, numBuckets, arr[i]);
    }

    sortBuckets(buckets, numBuckets);

    printf("Sorted array: ");
    for (int i = 0; i < numElements; i++) {
        int index = arr[i] / MAX_RANGE;
        printf("%d ", buckets[index].value);
    }

    free(arr);
    free(buckets);

    return 0;
}