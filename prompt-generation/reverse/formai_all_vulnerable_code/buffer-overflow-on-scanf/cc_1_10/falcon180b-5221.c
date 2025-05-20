//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void bucketSort(int arr[], int n) {
    int bucket[MAX_SIZE];
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int bucketSize = range / n;

    for (int i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / bucketSize;
        bucket[bucketIndex]++;
    }

    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[index] = i * bucketSize + min + j * bucketSize;
            index++;
        }
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();

    bucketSort(arr, n);

    clock_t end = clock();

    double timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %lf seconds\n", timeTaken);

    return 0;
}