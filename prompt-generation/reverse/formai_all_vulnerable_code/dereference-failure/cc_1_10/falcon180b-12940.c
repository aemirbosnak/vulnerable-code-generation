//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000
#define MAX_RANGE 1000

typedef struct {
    int *a;
    int size;
} Array;

void createArray(Array *a, int size) {
    a->a = (int *)malloc(size * sizeof(int));
    a->size = size;
    for (int i = 0; i < size; i++) {
        a->a[i] = rand() % MAX_RANGE;
    }
}

void printArray(Array a) {
    for (int i = 0; i < a.size; i++) {
        printf("%d ", a.a[i]);
    }
    printf("\n");
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void bucketSort(Array a) {
    int range = MAX_RANGE / a.size;
    int *buckets = (int *)malloc(a.size * sizeof(int));

    for (int i = 0; i < a.size; i++) {
        int index = a.a[i] / range;
        buckets[index]++;
    }

    for (int i = 1; i < a.size; i++) {
        buckets[i] += buckets[i - 1];
    }

    for (int i = a.size - 1; i >= 0; i--) {
        for (int j = 0; j < buckets[i]; j++) {
            a.a[--a.size] = i * MAX_RANGE + j * range;
        }
    }

    free(buckets);
}

int main() {
    Array a;
    createArray(&a, MAX_SIZE);
    printArray(a);

    clock_t start = clock();
    bucketSort(a);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n", time_taken);

    printArray(a);

    return 0;
}