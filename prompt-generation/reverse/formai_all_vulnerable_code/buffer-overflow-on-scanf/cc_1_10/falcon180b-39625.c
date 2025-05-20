//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

/* Function to swap two elements */
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Function to partition the array */
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

/* Function to perform bucket sort */
void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucketSize = max / n;
    int* buckets[n];

    for (int i = 0; i < n; i++) {
        buckets[i] = (int*)malloc(bucketSize * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] >= i * bucketSize && arr[j] < (i + 1) * bucketSize) {
                buckets[i][j - i * bucketSize] = arr[j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = i * bucketSize; j < (i + 1) * bucketSize; j++) {
            if (buckets[i][j - i * bucketSize]!= 0) {
                arr[k++] = buckets[i][j - i * bucketSize];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
}

/* Function to generate random array */
void generateArray(int arr[], int n) {
    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX;
    }
}

/* Function to print array */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    generateArray(arr, n);
    printf("Unsorted array:\n");
    printArray(arr, n);

    bucketSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);

    free(arr);
    return 0;
}