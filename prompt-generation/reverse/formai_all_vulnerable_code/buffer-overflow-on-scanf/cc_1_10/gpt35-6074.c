//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: accurate
#include <stdio.h>

void bucketSort(float arr[], int n) {
    // Create n empty buckets
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;
 
    // Add elements into the buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] * n;
        count[bucketIndex]++;
    }
 
    // Sort the elements in each bucket
    for (i = 0; i < n; i++) {
        int k = count[i];
        if (k > 0) {
            float bucket[k];
            for (j = 0; j < k; j++)
                bucket[j] = 0.0;
 
            for (j = 0; j < n; j++) {
                int index = arr[j] * n;
                if (index == i)
                    bucket[--count[i]] = arr[j];
            }
 
            for (j = 0; j < k; j++) {
                arr[j] = bucket[j];
            }
        }
    }
}

int main() {
    printf("Bucket Sort Implementation\n");
    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    float arr[n];
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    printf("Given array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
 
    bucketSort(arr, n);
 
    printf("\nSorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    return 0;
}