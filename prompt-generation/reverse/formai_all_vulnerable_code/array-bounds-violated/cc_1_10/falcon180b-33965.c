//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
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
        bucket[arr[i] - min]++;
    }

    for (int i = 1; i < n; i++) {
        bucket[i] += bucket[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        arr[bucket[arr[i] - min] - 1] = arr[i];
        bucket[arr[i] - min]--;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        swap(&arr[i], &arr[rand() % n]);
    }

    printf("Unsorted array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}