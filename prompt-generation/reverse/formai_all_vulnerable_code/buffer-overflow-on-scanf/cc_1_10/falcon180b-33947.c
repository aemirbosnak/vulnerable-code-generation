//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_VALUE 1000000

int *bucketSort(int *arr, int size) {
    int *buckets = (int *)malloc(MAX_VALUE * sizeof(int));
    int i, j, count = 0;
    for (i = 0; i < MAX_VALUE; i++) {
        buckets[i] = 0;
    }
    for (i = 0; i < size; i++) {
        count++;
        buckets[arr[i]]++;
    }
    int *sortedArr = (int *)malloc(size * sizeof(int));
    for (i = 0; i < MAX_VALUE; i++) {
        for (j = 0; j < buckets[i]; j++) {
            sortedArr[count] = i;
            count++;
        }
    }
    for (i = 0; i < size; i++) {
        arr[i] = sortedArr[i];
    }
    free(buckets);
    free(sortedArr);
    return arr;
}

int main() {
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter %d integers:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start, end;
    start = clock();
    arr = bucketSort(arr, size);
    end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %lf seconds\n", elapsed);
    free(arr);
    return 0;
}