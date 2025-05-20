//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void bucketSort(int arr[], int n) {
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
    int *bucket = (int *)malloc(range * sizeof(int));
    int *count = (int *)malloc(range * sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int index = (arr[i] - min) / (max - min) * range;
        bucket[index] = arr[i];
        count[index]++;
    }

    int i = 0;
    for (int j = 0; j < range; j++) {
        if (count[j] > 0) {
            for (int k = 0; k < count[j]; k++) {
                output[i++] = bucket[j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(bucket);
    free(count);
    free(output);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();
    bucketSort(arr, n);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for bucket sort: %lf seconds\n", time_taken);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}