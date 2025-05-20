//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int bottom;
    int top;
    int *array;
} Bucket;

void bucketSort(int arr[], int n) {
    int i, bucketIndex;
    Bucket buckets[10];

    for (i = 0; i < 10; i++) {
        buckets[i].bottom = i * MAX_SIZE / 10;
        buckets[i].top = (i + 1) * MAX_SIZE / 10;
        buckets[i].array = calloc(MAX_SIZE / 10, sizeof(int));
    }

    for (i = 0; i < n; i++) {
        bucketIndex = (arr[i] / (MAX_SIZE / 10)) * (MAX_SIZE / 10) + arr[i] % (MAX_SIZE / 10);
        buckets[bucketIndex / 10].array[bucketIndex % (MAX_SIZE / 10)] = arr[i];
    }

    for (i = 0; i < 10; i++) {
        int j, temp;

        for (j = 0; j < MAX_SIZE / 10 - 1; j++) {
            if (buckets[i].array[j] > buckets[i].array[j + 1]) {
                temp = buckets[i].array[j];
                buckets[i].array[j] = buckets[i].array[j + 1];
                buckets[i].array[j + 1] = temp;
            }
        }

        for (j = i * (MAX_SIZE / 10), temp = 0; j < (i + 1) * (MAX_SIZE / 10); j++) {
            arr[j] = buckets[i].array[j - i * (MAX_SIZE / 10)];
        }
    }

    for (i = 0; i < 10; i++) {
        free(buckets[i].array);
    }
}

int main() {
    int arr[MAX_SIZE], i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}