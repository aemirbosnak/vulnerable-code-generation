//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define BUCKET_SIZE 10

void createBuckets(int arr[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bucketSort(int arr[], int n) {
    int i, j;
    int* buckets[BUCKET_SIZE];

    for (i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] / (MAX_SIZE / BUCKET_SIZE);
        int indexInBucket = 0;
        while (indexInBucket < n && buckets[bucketIndex][indexInBucket]!= -1) {
            indexInBucket++;
        }
        buckets[bucketIndex][indexInBucket] = arr[i];
    }

    int index = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (buckets[i][j]!= -1) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int* arr = malloc(sizeof(int) * n);

    srand(time(NULL));
    createBuckets(arr, n);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}