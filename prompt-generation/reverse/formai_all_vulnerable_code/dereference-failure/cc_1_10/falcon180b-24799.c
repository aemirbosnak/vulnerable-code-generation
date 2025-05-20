//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n);

int main() {
    int arr[MAX_SIZE], n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bucketSort(int arr[], int n) {
    int bucket[MAX_SIZE];
    int max = arr[0], min = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int size = range / n;

    printf("Range: %d, Size: %d\n", range, size);

    for (int i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / size;
        bucket[bucketIndex]++;
    }

    for (int i = 1; i < n; i++) {
        bucket[i] += bucket[i - 1];
    }

    int j = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        arr[j--] = arr[bucket[i] - 1];
        bucket[i]--;
    }
}