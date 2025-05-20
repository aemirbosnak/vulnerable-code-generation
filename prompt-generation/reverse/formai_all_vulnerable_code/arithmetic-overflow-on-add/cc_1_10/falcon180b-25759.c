//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucketSort(int arr[], int n) {
    int i, j, max, min;
    int *bucket[n];

    for(i = 0; i < n; i++) {
        bucket[i] = (int*)malloc(sizeof(int));
    }

    for(i = 0; i < n; i++) {
        *(bucket[arr[i]]) = i;
    }

    max = *(bucket[0]);
    min = *(bucket[0]);

    for(i = 1; i < n; i++) {
        if(*(bucket[i]) > max) {
            max = *(bucket[i]);
        }
        if(*(bucket[i]) < min) {
            min = *(bucket[i]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = *(bucket[i]); j <= max; j++) {
            printf("%d ", j);
        }
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorting:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nArray after sorting:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}