//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int *data;
    int size;
} Bucket;

void initBucket(Bucket *b) {
    b->data = malloc(MAX_SIZE * sizeof(int));
    b->size = 0;
}

void insertBucket(Bucket *b, int value) {
    if (b->size >= MAX_SIZE) {
        printf("Bucket is full\n");
        return;
    }
    b->data[b->size++] = value;
}

void printBucket(Bucket b) {
    int i;
    for (i = 0; i < b.size; i++) {
        printf("%d ", b.data[i]);
    }
    printf("\n");
}

void sortBucket(Bucket b) {
    int i, j, temp;
    for (i = 0; i < b.size - 1; i++) {
        for (j = 0; j < b.size - i - 1; j++) {
            if (b.data[j] > b.data[j + 1]) {
                temp = b.data[j];
                b.data[j] = b.data[j + 1];
                b.data[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i, value;
    Bucket bucket;
    initBucket(&bucket);

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insertBucket(&bucket, value);
    }

    printf("Bucket before sorting:\n");
    printBucket(bucket);

    sortBucket(bucket);

    printf("Bucket after sorting:\n");
    printBucket(bucket);

    return 0;
}