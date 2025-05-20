//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // maximum number of elements in the array

void bucketSort(int arr[], int n) {
    int i, j;
    int *bucket[MAX_SIZE]; // array of buckets
    int max = arr[0]; // find the maximum element in the array
    int min = arr[0]; // find the minimum element in the array

    // create empty buckets
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *) malloc(n * sizeof(int));
    }

    // put elements in the appropriate bucket
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) * MAX_SIZE / (max - min);
        bucket[j] = (int *) realloc(bucket[j], (j + 1) * sizeof(int));
        bucket[j][j] = arr[i];
    }

    // concatenate the sorted buckets
    int k = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < bucket[i][0]; j++) {
            arr[k++] = bucket[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
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