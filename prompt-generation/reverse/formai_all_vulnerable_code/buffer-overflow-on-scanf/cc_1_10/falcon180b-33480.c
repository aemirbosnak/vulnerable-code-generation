//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void bucketSort(int arr[], int size) {
    int i, j, n;
    int *bucket[MAX_SIZE];

    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(sizeof(int));
    }

    for (i = 0; i < size; i++) {
        n = arr[i] * MAX_SIZE;
        bucket[n] = (int *)realloc(bucket[n], sizeof(int) * (++bucket[n][0]));
        bucket[n][bucket[n][0] - 1] = arr[i];
    }

    for (i = 0; i < size; i++) {
        arr[i] = bucket[arr[i] * MAX_SIZE][0];
    }

    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

int main() {
    int i, n;
    int arr[MAX_SIZE];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    printf("Before Sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nAfter Sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}