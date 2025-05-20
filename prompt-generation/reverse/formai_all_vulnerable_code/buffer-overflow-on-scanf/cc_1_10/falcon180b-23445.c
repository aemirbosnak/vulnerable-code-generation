//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define RANGE 100

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bucketSort(int arr[], int n) {
    int i, j, count[MAX] = {0};
    int *bucket[MAX];

    for (i = 0; i < MAX; i++)
        bucket[i] = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        count[(arr[i] / RANGE) * RANGE]++;
    }

    for (i = 0; i < MAX; i++) {
        if (count[i]!= 0) {
            for (j = 0; j < count[i]; j++) {
                bucket[i][j] = i * RANGE;
            }
            for (j = 0; j < n; j++) {
                if ((arr[j] / RANGE) * RANGE == i) {
                    bucket[i][count[i]++] = arr[j];
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        arr[i] = bucket[((arr[i] / RANGE) * RANGE)][--count[(arr[i] / RANGE) * RANGE]];
    }

    for (i = 0; i < MAX; i++) {
        free(bucket[i]);
    }
}

int main() {
    int i, n;
    int arr[MAX];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        int randIndex = rand() % n;
        swap(&arr[i], &arr[randIndex]);
    }

    printf("Unsorted array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}