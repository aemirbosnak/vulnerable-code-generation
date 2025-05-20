//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000
#define MAX_VALUE 1000

void bucketSort(int arr[], int n) {
    int i, j, k;
    int *bucket[MAX_VALUE];

    for (i = 0; i < MAX_VALUE; i++) {
        bucket[i] = (int *) malloc(SIZE * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        k = arr[i] / 10;
        j = arr[i] % 10;
        bucket[k][j] = arr[i];
    }

    for (i = 0; i < MAX_VALUE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (bucket[i][j]!= 0) {
                arr[k] = bucket[i][j];
                k++;
            }
        }
    }
}

int main() {
    int i, n;
    int *arr;

    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}