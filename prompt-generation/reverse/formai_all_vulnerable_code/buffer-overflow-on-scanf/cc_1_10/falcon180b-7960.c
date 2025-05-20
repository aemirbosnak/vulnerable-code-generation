//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int bucketSize = max / n;
    int* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = (int*)malloc(bucketSize * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] >= j * bucketSize && arr[i] < (j + 1) * bucketSize) {
                int index = arr[i] - j * bucketSize;
                buckets[j][index] = arr[i];
            }
        }
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSize; j++) {
            if (buckets[i][j]!= 0) {
                arr[k++] = buckets[i][j];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    generateRandomArray(arr, n);
    printf("Before sorting:\n");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("After sorting:\n");
    printArray(arr, n);
    return 0;
}