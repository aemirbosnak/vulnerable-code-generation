//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = findMax(arr, n);
    int bucketSize = max / n;
    int *buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = malloc(bucketSize * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] >= i * bucketSize && arr[j] < (i + 1) * bucketSize) {
                int k = arr[j] / bucketSize;
                buckets[k] = realloc(buckets[k], (k + 1) * sizeof(int));
                buckets[k][k] = arr[j];
            }
        }
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] >= i * bucketSize && arr[j] < (i + 1) * bucketSize) {
                arr[index++] = buckets[j][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
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
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}