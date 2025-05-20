//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int compare(const void *a, const void *b) {
    int *ia = (int *)a;
    int *ib = (int *)b;
    return (*ia - *ib);
}

void bucketSort(int arr[], int n) {
    int i, j, k, bucket[MAX_SIZE] = {0};
    int *temp = (int *)malloc(n * sizeof(int));

    // Counting the frequency of each element
    for (i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    // Modify the bucket to store the actual position of each element
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] += bucket[i - 1];
    }

    // Sorting the array
    for (i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    for (i = 0; i < n; i++) {
        j = temp[i];
        k = bucket[j];
        bucket[j]--;
        while (k > 0 && bucket[k - 1] == 0) {
            k--;
        }
        while (k > 0 && temp[k - 1] > j) {
            temp[k] = temp[k - 1];
            k--;
        }
        temp[k] = j;
    }

    for (i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    free(temp);
}

int main() {
    int arr[] = { 4, 2, 7, 2, 1, 3, 6, 8, 9, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}