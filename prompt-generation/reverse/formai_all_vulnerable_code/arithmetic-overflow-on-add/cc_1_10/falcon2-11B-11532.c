//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 100

void bucketSort(int arr[], int n) {
    int i, j, k, temp;
    int buckets[MAX_BUCKETS];

    for (i = 0; i < n; i++) {
        buckets[arr[i] % MAX_BUCKETS]++;
    }

    for (i = 0; i < MAX_BUCKETS; i++) {
        for (j = 0; j < buckets[i]; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        k = arr[i] % MAX_BUCKETS;
        j = 0;
        while (buckets[k] > j) {
            j++;
        }
        temp = arr[i];
        arr[i] = arr[buckets[k] - j];
        arr[buckets[k] - j] = temp;
        buckets[k]--;
    }

    printf("Sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 3, 6, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    return 0;
}