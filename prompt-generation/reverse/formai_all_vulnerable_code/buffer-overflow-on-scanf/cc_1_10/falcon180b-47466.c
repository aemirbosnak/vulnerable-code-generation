//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define RANGE 100

void generateArray(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % RANGE;
    }
}

void bucketSort(int arr[], int n) {
    int *buckets[RANGE];
    for (int i = 0; i < RANGE; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / RANGE;
        int *bucket = buckets[bucketIndex];
        int *p = bucket;
        while (*p!= -1) {
            p++;
        }
        *p = i;
    }

    int j = 0;
    for (int i = 0; i < RANGE; i++) {
        int *bucket = buckets[i];
        while (*bucket!= -1) {
            int index = *bucket;
            arr[j] = index;
            bucket++;
            j++;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    generateArray(arr, n);

    printf("Before sorting:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("After sorting:\n");
    printArray(arr, n);

    return 0;
}