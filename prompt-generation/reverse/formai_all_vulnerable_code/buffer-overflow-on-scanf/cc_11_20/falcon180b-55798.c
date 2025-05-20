//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

int main() {
    int n, i, j, max, min;
    int *array;
    double start_time, end_time;
    int **bucket;
    int num_buckets;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    max = array[0];
    min = array[0];

    for (i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        } else if (array[i] < min) {
            min = array[i];
        }
    }

    num_buckets = ceil((max - min) / (MAX_RANGE / n));

    bucket = (int **)malloc(num_buckets * sizeof(int *));
    for (i = 0; i < num_buckets; i++) {
        bucket[i] = (int *)malloc(n * sizeof(int));
    }

    start_time = clock();

    for (i = 0; i < n; i++) {
        int bucket_index = (array[i] - min) / (MAX_RANGE / n);
        bucket[bucket_index][i] = array[i];
    }

    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < n; j++) {
            array[j] = bucket[i][j];
        }
    }

    end_time = clock();

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    free(array);

    for (i = 0; i < num_buckets; i++) {
        free(bucket[i]);
    }

    free(bucket);

    printf("Time taken: %f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    return 0;
}