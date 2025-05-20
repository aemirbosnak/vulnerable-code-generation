//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n);

int main() {
    int arr[MAX_SIZE], n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

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

void bucketSort(int arr[], int n) {
    int i, j, min, max, range, count[MAX_SIZE] = {0};

    // Find the minimum and maximum elements in the array
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

    // Calculate the range of the array
    range = max - min + 1;

    // Create n empty buckets
    for (i = 0; i < n; i++) {
        arr[i] = -1;
    }

    // Distribute the elements into the buckets
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / range * n;
        if (count[j] == 0) {
            arr[j] = arr[i];
            count[j]++;
        } else {
            arr[j + 1] = arr[i];
            count[j + 1]++;
        }
    }

    // Copy the elements back to the original array
    for (i = 0; i < n; i++) {
        if (arr[i]!= -1) {
            arr[i] = arr[i];
        }
    }
}