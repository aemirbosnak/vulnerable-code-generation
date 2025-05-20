//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

/* Function to perform insertion sort */
void insertionSort(int* arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* Function to perform bucket sort */
void bucketSort(float* arr, int n) {
    int i, j;
    float bucket[n];

    /* Initialize all bucket values to 0 */
    for (i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    /* Fill the bucket with values */
    for (i = 0; i < n; i++) {
        int index = arr[i] * n;
        bucket[index] = arr[i];
    }

    /* Sort each bucket */
    for (i = 0; i < n; i++) {
        int numItems = 0;
        for (j = 0; j < n; j++) {
            if (bucket[i] > 0) {
                numItems++;
            }
        }
        insertionSort(bucket, numItems);
    }

    /* Print the sorted numbers */
    printf("The sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%f ", bucket[i]);
    }
    printf("\n");
}

/* Main function */
int main() {
    int n, i;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    float arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    bucketSort(arr, n);
    return 0;
}