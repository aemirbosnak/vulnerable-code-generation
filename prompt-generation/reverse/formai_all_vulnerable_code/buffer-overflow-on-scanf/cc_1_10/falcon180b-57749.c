//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void merge(int arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int B[MAX];

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            B[k++] = arr[i++];
        } else {
            B[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        B[k++] = arr[i++];
    }

    while (j <= right) {
        B[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = B[i];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[MAX];
    int i, n, time1, time2;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    time1 = clock();
    mergeSort(arr, 0, n - 1);
    time2 = clock();

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %d ms\n", (time2 - time1) * 1000 / CLOCKS_PER_SEC);

    return 0;
}