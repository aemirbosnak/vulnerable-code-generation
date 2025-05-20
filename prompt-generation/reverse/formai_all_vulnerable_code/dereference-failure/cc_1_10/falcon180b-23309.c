//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void bucketSort(int arr[], int n) {
    int max = arr[0], min = arr[0], range;
    int *bucket = (int *) malloc(n * sizeof(int));
    int i, j, k;

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } else if (arr[i] < min) {
            min = arr[i];
        }
    }

    range = max - min + 1;
    for (i = 0; i < range; i++) {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    for (i = 1; i < range; i++) {
        bucket[i] += bucket[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        arr[bucket[arr[i] - min] - 1] = arr[i];
        bucket[arr[i] - min]--;
    }

    free(bucket);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}