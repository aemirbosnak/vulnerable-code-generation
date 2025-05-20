//Gemma-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void bucket_sort(int **arr, int n) {
    int i, j, k, bucket_size, min, max, range, hash_func(int);
    int **buckets = NULL;

    min = arr[0][0];
    max = arr[0][0];
    for (i = 0; i < n; i++) {
        min = fmin(min, arr[i][0]);
        max = fmax(max, arr[i][0]);
    }

    range = max - min + 1;
    bucket_size = range / MAX_SIZE;

    buckets = (int **)malloc(bucket_size * sizeof(int *));
    for (i = 0; i < bucket_size; i++) {
        buckets[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        k = hash_func(arr[i][0]) * bucket_size;
        buckets[k][arr[i][0]] = arr[i];
    }

    for (i = 0; i < bucket_size; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (buckets[i][j] != NULL) {
                printf("%d ", buckets[i][j]);
            }
        }
        printf("\n");
    }

    free(buckets);
}

int hash_func(int num) {
    return num % MAX_SIZE;
}

int main() {
    int **arr = NULL;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(2 * sizeof(int));
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    bucket_sort(arr, n);

    free(arr);

    return 0;
}