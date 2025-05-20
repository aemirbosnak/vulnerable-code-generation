//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

void bucketSort(int arr[], int n) {
    int i, j, index, max, min;
    int *bucket[n];

    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++) {
        bucket[arr[i] / n] = (int *)realloc(bucket[arr[i] / n], sizeof(int) * (i + 1));
        bucket[arr[i] / n][i] = arr[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (bucket[i][j]!= -1) {
                arr[j] = bucket[i][j];
                j++;
            }
        }
    }
}

int main() {
    int i, n;
    int *arr;

    srand(time(NULL));
    n = rand() % MAX + 1;
    arr = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX;
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}