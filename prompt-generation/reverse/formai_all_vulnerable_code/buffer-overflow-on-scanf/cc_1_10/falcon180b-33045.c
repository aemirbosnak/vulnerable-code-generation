//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucketSort(int arr[], int n) {
    int i, j, k, max, min, range, bucket[n];
    int *temp = (int *)malloc(n * sizeof(int));

    // Find the range of the array
    max = arr[0];
    min = arr[0];
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    range = max - min + 1;

    // Create empty buckets
    for (i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    // Place elements in the buckets
    for (i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    // Place elements in the sorted array
    for (i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket[i]; j++) {
            arr[j + i * range] = temp[i];
        }
    }

    // Free the temporary array
    free(temp);
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    srand(time(NULL));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Unsorted array:\n");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}