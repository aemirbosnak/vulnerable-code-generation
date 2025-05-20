//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int i, j, k, range;
    int *bucket[n];
    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(sizeof(int));
    }
    for (i = 0; i < n; i++) {
        *(bucket[arr[i] / n]) = arr[i];
    }
    for (i = 0; i < n; i++) {
        range = i * n;
        for (j = 0; j < n; j++) {
            if (*(bucket[j])!= NULL) {
                arr[range] = *(bucket[j]);
                range++;
            }
        }
    }
    for (i = 0; i < n; i++) {
        free(bucket[i]);
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
    int i, n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Unsorted array:\n");
    printArray(arr, n);
    srand(time(NULL));
    bucketSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}