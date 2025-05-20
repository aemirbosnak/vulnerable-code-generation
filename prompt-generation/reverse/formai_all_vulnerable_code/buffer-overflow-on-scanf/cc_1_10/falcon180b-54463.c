//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct {
    int size;
    int* arr;
} Bucket;

void createBucket(Bucket* b, int max) {
    b->size = max;
    b->arr = (int*) malloc(max * sizeof(int));
    memset(b->arr, 0, max * sizeof(int));
}

void insertBucket(Bucket* b, int val) {
    if (b->size == 0) {
        createBucket(b, MAX_SIZE);
    }
    if (val < 0) {
        val = -val;
    }
    if (val >= MAX_SIZE) {
        val = MAX_SIZE - 1;
    }
    b->arr[val]++;
}

void printBucket(Bucket* b) {
    for (int i = 0; i < b->size; i++) {
        printf("%d ", b->arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    Bucket* buckets = (Bucket*) malloc(n * sizeof(Bucket));
    for (int i = 0; i < n; i++) {
        createBucket(&buckets[i], MAX_SIZE);
    }
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insertBucket(&buckets[i], val);
    }
    for (int i = 0; i < n; i++) {
        printBucket(&buckets[i]);
    }
    return 0;
}