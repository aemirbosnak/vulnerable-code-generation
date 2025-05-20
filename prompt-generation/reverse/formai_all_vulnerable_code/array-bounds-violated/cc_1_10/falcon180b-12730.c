//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int n) {
    int i, j;
    int bucket[MAX_SIZE] = {0};
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum values in the array
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the bucket size
    int bucket_size = (max - min) / n;

    // Place the elements in the correct bucket
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / bucket_size;
        bucket[j]++;
    }

    // Place the elements back into the array
    for (i = n - 1; i >= 0; i--) {
        if (bucket[i]!= 0) {
            arr[i] = min;
            min += bucket_size;
            bucket[i]--;
        }
    }
}

int main() {
    int arr[] = {10, 5, 2, 8, 1, 4, 6, 3, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}