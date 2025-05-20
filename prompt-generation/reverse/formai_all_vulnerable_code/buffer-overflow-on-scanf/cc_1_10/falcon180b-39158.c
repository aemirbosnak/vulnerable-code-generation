//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void bucketSort(int arr[], int n) {
    int i, j, max = arr[0], min = arr[0], range, temp[n];

    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    range = max - min + 1;

    int *bucket[range];

    for (i = 0; i < range; i++) {
        bucket[i] = (int *) malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / (max - min) * range;
        bucket[j] = (int *) realloc(bucket[j], sizeof(int) * (n + 1));
        bucket[j][n - 1] = arr[i];
    }

    i = 0;
    for (j = 0; j < range; j++) {
        if (bucket[j]!= NULL) {
            for (int k = 0; k < n; k++) {
                temp[i++] = bucket[j][k];
            }
        }
    }

    for (j = 0; j < n; j++) {
        arr[j] = temp[j];
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
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