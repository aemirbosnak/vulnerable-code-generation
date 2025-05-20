//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    int i, n, max, min;
    int *arr;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    start = clock();
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min || min == 0) {
            min = arr[i];
        }
    }

    double range = (double)max - (double)min;
    double bucket_size = range / (double)n;

    int *bucket[n];

    for (i = 0; i < n; i++) {
        bucket[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    start = clock();
    for (i = 0; i < n; i++) {
        int index = (int)((double)arr[i] - (double)min) / bucket_size;
        bucket[index] = realloc(bucket[index], (index + 1) * sizeof(int));
        bucket[index][index] = arr[i];
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Bucket Sort took %lf seconds to execute.\n", cpu_time_used);

    for (i = 0; i < n; i++) {
        printf("Bucket %d: ", i);
        for (int j = 0; j <= i; j++) {
            printf("%d ", bucket[i][j]);
        }
        printf("\n");
    }

    return 0;
}