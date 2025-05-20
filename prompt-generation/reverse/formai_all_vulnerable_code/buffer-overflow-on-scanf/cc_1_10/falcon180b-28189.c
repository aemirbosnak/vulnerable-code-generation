//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

void bucketSort(int arr[], int n) {
    int i, j, k;
    int buckets[MAX_SIZE];
    int max = arr[0];
    int min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int bucketSize = range / n;

    for (i = 0; i < n; i++) {
        buckets[i] = 0;
    }

    for (i = 0; i < n; i++) {
        k = (arr[i] - min) / bucketSize;
        buckets[k]++;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < buckets[i]; j++) {
            printf("%d ", arr[i]);
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    return 0;
}