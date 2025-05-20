//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define BUCKET_SIZE 10

void bucketSort(int arr[], int n);

int main() {
    int arr[MAX_SIZE], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bucketSort(int arr[], int n) {
    int i, j, count[BUCKET_SIZE] = {0};
    int bucket[MAX_SIZE];

    for (i = 0; i < n; i++) {
        count[(arr[i] / BUCKET_SIZE) % BUCKET_SIZE]++;
    }

    for (i = 0; i < BUCKET_SIZE; i++) {
        if (count[i] > 0) {
            for (j = 0; j < count[i]; j++) {
                bucket[j] = i * BUCKET_SIZE;
                count[i]--;
            }
        }
    }

    for (i = 0; i < n; i++) {
        int index = (arr[i] / BUCKET_SIZE) % BUCKET_SIZE;
        int k = 0;

        while (bucket[k] < arr[i]) {
            arr[bucket[k]] = arr[k];
            bucket[k] += BUCKET_SIZE;
            k++;
        }

        arr[bucket[k]] = arr[i];
        bucket[k] += BUCKET_SIZE;
    }
}