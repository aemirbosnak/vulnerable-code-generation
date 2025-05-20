//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n) {
    int i, j, max, min;
    int *bucket[MAX_SIZE];

    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] *= -1;
        }
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int bucketSize = n / range;

    for (i = 0; i < n; i++) {
        j = arr[i] - min;
        bucket[j] = realloc(bucket[j], sizeof(int) * (bucketSize + 1));
        bucket[j][bucketSize] = arr[i];
        bucketSize++;
    }

    int k = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < bucketSize; j++) {
            arr[k++] = bucket[i][j];
        }
    }

    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}