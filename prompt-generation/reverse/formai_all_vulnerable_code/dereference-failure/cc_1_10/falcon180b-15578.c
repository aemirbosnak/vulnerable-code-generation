//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX 1000000

void bucketSort(int arr[], int n) {
    int i, j, count[MAX] = {0};
    float range;
    int *bucket[MAX];

    for (i = 0; i < MAX; i++) {
        bucket[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        count[(int)arr[i]]++;
    }

    for (i = 0; i < MAX; i++) {
        if (count[i]!= 0) {
            range = (float)n / count[i];
            for (j = 0; j < count[i]; j++) {
                bucket[(int)arr[j]][j] = i * range + j;
            }
        }
    }

    for (i = 0; i < n; i++) {
        arr[i] = bucket[(int)arr[i]][i];
    }

    for (i = 0; i < MAX; i++) {
        free(bucket[i]);
    }
}

int main() {
    int i, n, max, min;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}