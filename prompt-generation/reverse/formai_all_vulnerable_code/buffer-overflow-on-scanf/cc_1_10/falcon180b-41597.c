//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define RANGE 100

void bucketSort(int arr[], int n) {
    int i, j, k, max, min, bucket[MAX];
    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            arr[i] = -arr[i];
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
        bucket[i] = 0;
    }
    for (i = 0; i < n; i++) {
        k = (arr[i] - min) * RANGE / (max - min);
        bucket[k]++;
    }
    for (i = 1; i <= max - min; i++) {
        bucket[i] += bucket[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        k = (arr[i] - min) * RANGE / (max - min);
        arr[bucket[k] - 1] = arr[i];
        bucket[k]--;
    }
}

int main() {
    int i, n;
    srand(time(NULL));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    bucketSort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}