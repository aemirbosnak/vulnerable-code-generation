//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the maximum value in the array
float max(float arr[], int n) {
    float max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform the bucket sort
void bucketSort(float arr[], int n) {
    int max_val = max(arr, n);
    int bucket_size = ceil(max_val / n);
    float *bucket[n];
    for (int i = 0; i < n; i++) {
        bucket[i] = malloc(sizeof(float) * bucket_size);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] >= i * bucket_size && arr[j] < (i + 1) * bucket_size) {
                bucket[i][j - i * bucket_size] = arr[j];
            }
        }
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket_size; j++) {
            arr[k++] = bucket[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    float arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    return 0;
}