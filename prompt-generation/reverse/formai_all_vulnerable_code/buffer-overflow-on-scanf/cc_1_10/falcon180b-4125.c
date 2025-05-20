//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} Bucket;

void createBuckets(Bucket *buckets, int size) {
    for (int i = 0; i < size; i++) {
        buckets[i].data = -1;
        buckets[i].index = -1;
    }
}

void insertElement(Bucket *buckets, int data, int size) {
    int index = data % size;
    int i = 0;
    while (buckets[index].data!= -1 && i < size) {
        index = (index + 1) % size;
        i++;
    }
    buckets[index].data = data;
    buckets[index].index = i;
}

void sortBuckets(Bucket *buckets, int size) {
    int i = 0;
    while (i < size) {
        int j = i;
        while (buckets[j].data == -1) {
            j = (j + 1) % size;
        }
        int temp = buckets[i].data;
        buckets[i].data = buckets[j].data;
        buckets[j].data = temp;
        buckets[i].index = buckets[j].index;
        buckets[j].index = i;
        i++;
    }
}

void printBuckets(Bucket *buckets, int size) {
    for (int i = 0; i < size; i++) {
        if (buckets[i].data!= -1) {
            printf("Bucket %d: %d\n", i, buckets[i].data);
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    Bucket *buckets = (Bucket *)malloc(MAX_SIZE * sizeof(Bucket));

    createBuckets(buckets, size);

    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        insertElement(buckets, arr[i], size);
    }

    sortBuckets(buckets, size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    free(buckets);

    return 0;
}