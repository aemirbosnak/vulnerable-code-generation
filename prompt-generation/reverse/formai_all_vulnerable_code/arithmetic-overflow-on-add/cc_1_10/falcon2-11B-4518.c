//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n) {
    int buckets[10] = {0};
    for (int i = 0; i < n; i++) {
        buckets[arr[i] % 10]++;
    }

    int min_bucket = 10;
    for (int i = 0; i < 10; i++) {
        if (buckets[i] < buckets[min_bucket]) {
            min_bucket = i;
        }
    }

    int *buckets_arr = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        buckets_arr[i] = buckets[i];
    }

    int *temp = malloc(sizeof(int) * 10);
    for (int i = 0; i < n; i++) {
        int bucket = arr[i] % 10;
        temp[bucket]++;
    }

    int *temp2 = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        temp2[i] = temp[i];
    }

    int *sorted = malloc(sizeof(int) * n);
    int j = 0;
    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < temp2[i]; k++) {
            sorted[j] = i * 10 + k;
            j++;
        }
    }

    int *sorted_arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        sorted_arr[i] = sorted[i];
    }

    int *temp3 = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        temp3[i] = sorted_arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp3[i];
    }

    free(buckets_arr);
    free(temp);
    free(temp2);
    free(sorted);
    free(sorted_arr);
    free(temp3);
}

int main() {
    int arr[] = {1, 5, 3, 2, 4, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}