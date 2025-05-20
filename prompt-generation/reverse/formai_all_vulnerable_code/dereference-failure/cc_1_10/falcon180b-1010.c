//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

void bucketSort(int arr[], int n) {
    int i, j, max, min;
    int *bucket[MAX_SIZE];

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

    for (i = 0; i <= max - min; i++) {
        bucket[i] = malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++) {
        j = (arr[i] - min) * (MAX_SIZE / (max - min));
        bucket[j] = realloc(bucket[j], sizeof(int) * (1 + bucket[j][0]));
        bucket[j][bucket[j][0]] = arr[i];
        bucket[j][0]++;
    }

    for (i = 0; i < n; i++) {
        arr[i] = bucket[0][i];
    }

    for (i = 1; i <= max - min; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n, i;

    srand(time(NULL));
    n = rand() % MAX_SIZE + 1;

    int arr[MAX_SIZE];

    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("After sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}