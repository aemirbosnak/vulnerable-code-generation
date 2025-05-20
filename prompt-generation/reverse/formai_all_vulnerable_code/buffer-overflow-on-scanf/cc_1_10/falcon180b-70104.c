//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int i, j, max, min;
    int bucket[MAX];

    // Find range of elements
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    // Calculate bucket size
    int bucketSize = (max - min) / n;

    // Initialize buckets
    for (i = 0; i < MAX; i++)
        bucket[i] = 0;

    // Place elements in buckets
    for (i = 0; i < n; i++) {
        int index = (arr[i] - min) / bucketSize;
        bucket[index]++;
    }

    // Sort elements
    for (i = 0; i < n; i++) {
        int index = (arr[i] - min) / bucketSize;
        bucket[index]--;
        arr[i] = min + index * bucketSize;
    }
}

int main() {
    int i, n;
    int arr[MAX];

    // Input elements
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Sort elements
    bucketSort(arr, n);

    // Print sorted elements
    printf("Sorted elements:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}