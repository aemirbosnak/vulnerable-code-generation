//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define RANGE 100

int *bucketSort(int arr[], int size) {
    int i, j, *bucket[MAX_SIZE], max, min;
    int range = RANGE;
    int *result = malloc(size * sizeof(int));
    if (result == NULL) {
        printf("Memory error!\n");
        exit(0);
    }

    for (i = 0; i < size; i++) {
        arr[i] = rand() % range;
    }

    for (i = 0; i < size; i++) {
        bucket[arr[i] / range] = malloc(sizeof(int));
        if (bucket[arr[i] / range] == NULL) {
            printf("Memory error!\n");
            exit(0);
        }
        bucket[arr[i] / range][0] = arr[i];
    }

    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= NULL) {
            for (j = 0; j < 1; j++) {
                result[j] = bucket[i][j];
            }
            free(bucket[i]);
        }
    }
    free(bucket);
    return result;
}

int main() {
    int size, *arr, *result;
    srand(time(NULL));
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    arr = malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory error!\n");
        exit(0);
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    result = bucketSort(arr, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free(arr);
    return 0;
}