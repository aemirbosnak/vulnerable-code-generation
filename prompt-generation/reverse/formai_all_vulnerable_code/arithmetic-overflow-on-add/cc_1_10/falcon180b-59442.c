//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bucketSort(int arr[], int n) {
    int i, j, k;
    int max = arr[0];
    int min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        } else if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int *bucket = (int *)malloc(range * sizeof(int));

    for (i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    for (i = 0; i < range; i++) {
        for (j = 0; j < bucket[i]; j++) {
            k = min + i;
            arr[k] = min + i;
            min++;
        }
    }

    free(bucket);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[MAX];

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, n);
    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nBucket Sorted array:\n");
    bucketSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}