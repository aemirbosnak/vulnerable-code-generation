//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void bucketSort(int arr[], int n) {
    int i, j, max, min, temp;
    int bucket[MAX_SIZE];

    /* Find minimum and maximum values in the array */
    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    /* Calculate bucket size */
    int bucketSize = (max - min + 1) / n;

    /* Create empty buckets */
    for (i = 0; i < n; i++) {
        bucket[i] = -1;
    }

    /* Insert elements into buckets */
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / bucketSize;
        if (bucket[j] == -1) {
            bucket[j] = i;
        }
        else {
            temp = bucket[j];
            while (temp!= -1) {
                temp = bucket[temp];
            }
            bucket[temp] = i;
        }
    }

    /* Sort elements in the array */
    for (i = 0; i < n; i++) {
        if (bucket[i]!= -1) {
            arr[i] = arr[bucket[i]];
            bucket[bucket[i]] = -1;
        }
    }
}

int main() {
    int arr[] = { 5, 8, 3, 2, 7, 1, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}