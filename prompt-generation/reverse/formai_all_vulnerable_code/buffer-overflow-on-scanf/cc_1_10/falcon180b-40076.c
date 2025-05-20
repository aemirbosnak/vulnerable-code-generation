//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void bucketSort(int arr[], int n);
void swap(int *a, int *b);

int main() {
    int i, n;
    int arr[SIZE];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("After sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bucketSort(int arr[], int n) {
    int i, j, max, min, temp;
    int bucket[10] = {0};

    // Find the maximum and minimum values in the array
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range and bucket size
    int range = max - min + 1;
    int bucketSize = range / 10;

    // Place the elements in the appropriate buckets
    for (i = 0; i < n; i++) {
        j = arr[i] / bucketSize;
        bucket[j]++;
    }

    // Rearrange the elements in the array
    i = 0;
    for (j = 0; j < 10; j++) {
        while (bucket[j] > 0) {
            arr[i] = j * bucketSize + min;
            i++;
            bucket[j]--;
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}