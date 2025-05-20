//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {
    // Create n empty buckets
    int i, j;
    int *count = (int*)calloc(n, sizeof(int));
    float **buckets = (float**)calloc(n, sizeof(float*));
    for (i = 0; i < n; i++) {
        buckets[i] = (float*)calloc(n, sizeof(float));
    }

    // Assign elements to the respective buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] * n;
        buckets[bucketIndex][count[bucketIndex]] = arr[i];
        count[bucketIndex]++;
    }

    // Sort the elements in each bucket using insertion sort
    for (i = 0; i < n; i++) {
        for (j = 1; j < count[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Combine the sorted buckets into a single array
    int index = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }
    free(buckets);
    free(count);
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float *arr = (float*)calloc(n, sizeof(float));
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%g ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}