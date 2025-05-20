//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int index;
} Bucket;

void createBuckets(Bucket* buckets, int n) {
    for (int i = 0; i < n; i++) {
        buckets[i].data = 0;
        buckets[i].index = -1;
    }
}

void insertElement(Bucket* buckets, int n, int element) {
    int index = element / n;
    buckets[index].data++;
    buckets[index].index = element;
}

void sortBucket(Bucket* buckets, int n) {
    for (int i = 0; i < n; i++) {
        if (buckets[i].data > 0) {
            int element = buckets[i].index;
            int j = 0;
            while (j < n && buckets[j].index!= element) {
                j++;
            }
            Bucket temp = buckets[i];
            buckets[i] = buckets[j];
            buckets[j] = temp;
        }
    }
}

void printBucket(Bucket* buckets, int n) {
    for (int i = 0; i < n; i++) {
        if (buckets[i].data > 0) {
            int element = buckets[i].index;
            printf("%d ", element);
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    Bucket* buckets = (Bucket*)malloc(n * sizeof(Bucket));
    createBuckets(buckets, n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        insertElement(buckets, n, element);
    }

    printf("Unsorted elements: ");
    printBucket(buckets, n);

    sortBucket(buckets, n);

    printf("Sorted elements: ");
    printBucket(buckets, n);

    free(buckets);
    return 0;
}