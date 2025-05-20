//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int i, j, max, min, range, *bucket[MAX];

    for (i = 0; i < n; ++i) {
        if (arr[i] < 0)
            arr[i] *= -1;
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; ++i) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    range = max - min + 1;

    for (i = 0; i < range; ++i)
        bucket[i] = NULL;

    for (i = 0; i < n; ++i) {
        j = arr[i] - min;
        *(bucket[j]) = arr[i];
        bucket[j] += sizeof(int);
    }

    for (i = 0; i < n; ++i) {
        j = arr[i] - min;
        arr[i] = *(bucket[j] - sizeof(int));
        bucket[j] -= sizeof(int);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}