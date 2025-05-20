//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

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
    int i, j, min, max;
    int *bucket[MAX_SIZE]; // array of buckets

    for (i = 0; i < n; i++) {
        bucket[arr[i]] = &arr[i];
    }

    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= NULL) {
            for (j = i; j < MAX_SIZE; j++) {
                if (bucket[j]!= NULL) {
                    if (*(int*)bucket[j] < *(int*)bucket[i]) {
                        int temp = *(int*)bucket[i];
                        *(int*)bucket[i] = *(int*)bucket[j];
                        *(int*)bucket[j] = temp;
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        arr[i] = *(int*)bucket[arr[i]];
    }
}