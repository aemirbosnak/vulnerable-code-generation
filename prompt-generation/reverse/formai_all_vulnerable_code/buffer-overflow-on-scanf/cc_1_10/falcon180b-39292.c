//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void bucket_sort(int *arr, int n) {
    int i, j, count[MAX_SIZE] = {0};
    int *bucket[MAX_SIZE];

    // find range of elements
    int min = arr[0];
    int max = arr[0];
    for (i = 0; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    // create empty buckets
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * n);
    }

    // put elements in appropriate buckets
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) * MAX_SIZE / (max - min);
        count[j]++;
        bucket[j][count[j] - 1] = arr[i];
    }

    // sort elements in each bucket
    for (i = 0; i < MAX_SIZE; i++) {
        qsort(bucket[i], count[i], sizeof(int), compare);
    }

    // combine sorted buckets back into original array
    int k = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[k++] = bucket[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();
    bucket_sort(arr, n);
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken: %.6f seconds\n", elapsed_time);

    return 0;
}