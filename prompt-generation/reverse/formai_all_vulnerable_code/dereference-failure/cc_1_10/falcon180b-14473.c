//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Bucket;

void createBuckets(Bucket* buckets, int size) {
    for (int i = 0; i < size; i++) {
        buckets[i].data = 0;
        buckets[i].index = -1;
    }
}

void insertElement(Bucket* buckets, int size, int element) {
    int index = element % size;
    if (buckets[index].data == 0) {
        buckets[index].data = element;
        buckets[index].index = 0;
    } else {
        int j = 0;
        while (j < buckets[index].data) {
            if (buckets[index].index == (j - 1)) {
                j++;
            } else {
                buckets[index].index++;
                break;
            }
        }
        buckets[index].data++;
    }
}

void sortElements(int* arr, Bucket* buckets, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i]!= 0) {
            insertElement(buckets, size, arr[i]);
        }
    }
}

void printElements(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    Bucket* buckets = (Bucket*)malloc(MAX_SIZE * sizeof(Bucket));
    createBuckets(buckets, MAX_SIZE);
    sortElements(arr, buckets, MAX_SIZE);
    printElements(arr, size);
    free(buckets);
    return 0;
}