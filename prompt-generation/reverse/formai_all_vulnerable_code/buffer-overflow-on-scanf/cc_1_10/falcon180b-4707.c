//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bucketSort(int arr[], int n) {
    int i, j, k, max, min;
    int *bucket[MAX_SIZE];

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_SIZE;
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

    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++) {
        j = arr[i] * MAX_SIZE / max;
        k = 0;
        while (bucket[j][k]!= 0) {
            k++;
        }
        bucket[j][k] = arr[i];
    }

    for (i = 0; i < n; i++) {
        k = 0;
        while (bucket[arr[i] * MAX_SIZE / max][k]!= arr[i]) {
            k++;
        }
        arr[i] = bucket[arr[i] * MAX_SIZE / max][k];
    }

    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}