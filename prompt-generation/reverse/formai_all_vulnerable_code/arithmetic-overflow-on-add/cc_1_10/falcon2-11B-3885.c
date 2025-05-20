//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void bucketSort(int arr[], int n) {
    int bucketSize = 10;
    int *bucket = (int *)malloc(bucketSize * sizeof(int));
    if (bucket == NULL) {
        printf("Memory allocation error");
        return;
    }

    for (int i = 0; i < n; i++) {
        int index = (arr[i] / bucketSize) % bucketSize;
        bucket[index] += arr[i];
    }

    int count = 0;
    for (int i = 0; i < bucketSize; i++) {
        if (bucket[i]!= 0) {
            count++;
            int *temp = (int *)malloc(count * sizeof(int));
            if (temp == NULL) {
                printf("Memory allocation error");
                return;
            }
            for (int j = 0; j < count; j++) {
                temp[j] = 0;
            }
            for (int j = 0; j < bucketSize; j++) {
                if (bucket[j]!= 0) {
                    temp[count - 1 - (bucket[j] / bucketSize) % bucketSize] += bucket[j];
                }
            }
            for (int j = 0; j < count; j++) {
                arr[i + j] = temp[j];
            }
            free(bucket);
            bucket = temp;
        }
    }
    free(bucket);
}

int main() {
    int arr[] = {5, 7, 2, 9, 4, 1, 3, 6, 8, 10, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}