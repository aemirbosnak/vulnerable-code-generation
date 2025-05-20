//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BUCKETS 100
#define MAX_NUMBERS 10000

void bucketSort(int arr[], int n) {
    int i, j, k, min, max, range;
    int *buckets[MAX_BUCKETS];
    for (i = 0; i < MAX_BUCKETS; i++) {
        buckets[i] = (int *)malloc(MAX_NUMBERS * sizeof(int));
    }
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
    range = max - min + 1;
    for (i = 0; i < n; i++) {
        k = (arr[i] - min) * MAX_BUCKETS / range;
        buckets[k] = realloc(buckets[k], sizeof(int) * (j + 1));
        buckets[k][j] = arr[i];
        j++;
    }
    i = 0;
    for (k = 0; k < MAX_BUCKETS; k++) {
        for (j = 0; j < j; j++) {
            arr[i] = buckets[k][j];
            i++;
        }
    }
    for (i = 0; i < MAX_BUCKETS; i++) {
        free(buckets[i]);
    }
}

int main() {
    int n, i, j;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}