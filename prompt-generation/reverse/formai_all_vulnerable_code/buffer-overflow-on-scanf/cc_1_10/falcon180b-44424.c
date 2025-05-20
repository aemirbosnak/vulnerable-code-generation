//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define RANGE 1000000

int rand_int(int max) {
    return rand() % max;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucket_sort(int arr[], int n) {
    int i, j, k, range, count[MAX] = {0};
    int *bucket[MAX];

    for (i = 0; i < n; i++) {
        range = RANGE / n;
        k = arr[i] / range;
        count[k]++;
    }

    for (i = 0; i < MAX; i++) {
        if (count[i] > 0) {
            bucket[i] = (int*)malloc(count[i] * sizeof(int));
        }
    }

    for (i = 0; i < n; i++) {
        range = RANGE / n;
        k = arr[i] / range;
        bucket[k][count[k] - 1] = arr[i];
        count[k]--;
    }

    for (i = 0; i < n; i++) {
        range = RANGE / n;
        k = arr[i] / range;
        arr[i] = bucket[k][0];
        for (j = 0; j < count[k] - 1; j++) {
            bucket[k][j] = bucket[k][j + 1];
        }
        count[k]--;
    }

    for (i = 0; i < MAX; i++) {
        free(bucket[i]);
    }
}

int main() {
    int i, n;
    srand(time(0));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        arr[i] = rand_int(RANGE);
    }

    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}