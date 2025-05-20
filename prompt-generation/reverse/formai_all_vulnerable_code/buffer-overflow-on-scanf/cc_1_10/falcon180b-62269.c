//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define BUCKET_SIZE 10

void bucketSort(int arr[], int n) {
    int i, j, temp;
    int *bucket[BUCKET_SIZE];

    for (i = 0; i < BUCKET_SIZE; i++) {
        bucket[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        j = arr[i] / BUCKET_SIZE;
        if (j >= BUCKET_SIZE) {
            j = BUCKET_SIZE - 1;
        }
        bucket[j] = (int *)realloc(bucket[j], (j + 1) * sizeof(int));
        bucket[j][j] = arr[i];
    }

    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 0; j < bucket[i][i]; j++) {
            arr[j] = bucket[i][j];
        }
    }

    for (i = 0; i < BUCKET_SIZE; i++) {
        free(bucket[i]);
    }
}

int main() {
    int n, i;
    int arr[MAX_SIZE];

    srand(time(NULL));

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}