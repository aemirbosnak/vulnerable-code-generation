//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void bucketSort(int *arr, int n) {
    int i, j, k, max, min;
    int *bucket[MAX_SIZE];

    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = NULL;
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

    for (i = 0; i < n; i++) {
        k = (arr[i] * MAX_SIZE) / (max - min + 1);
        bucket[k] = realloc(bucket[k], (k + 1) * sizeof(int));
        bucket[k][k] = arr[i];
    }

    for (i = 0; i < n; i++) {
        arr[i] = bucket[((arr[i] * MAX_SIZE) / (max - min + 1))][0];
    }
}

int main(int argc, char *argv[]) {
    int n, i, max, min;
    int *arr;

    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}