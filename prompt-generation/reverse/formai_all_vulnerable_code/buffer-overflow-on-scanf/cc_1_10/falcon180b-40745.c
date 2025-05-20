//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n) {
    int i, j, k, index;
    float range = (float)MAX_SIZE / n;
    int *bucket[MAX_SIZE];

    for (i = 0; i < n; i++) {
        index = (int)((arr[i] / range) * n);
        if (index == n) {
            index--;
        }
        if (bucket[index] == NULL) {
            bucket[index] = (int *)malloc(sizeof(int));
        }
        bucket[index] = (int *)realloc(bucket[index], sizeof(int) * ++k);
        bucket[index][k - 1] = arr[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            arr[i * n + j] = bucket[i][j];
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[MAX_SIZE];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}