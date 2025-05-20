//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void bucket_sort(int arr[], int n) {
    int i, j, max = arr[0], min = arr[0], range, count[MAX] = {0};
    int **bucket = (int**)malloc(MAX * sizeof(int*));

    for (i = 0; i < MAX; i++) {
        bucket[i] = (int*)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    range = max - min + 1;

    for (i = 0; i < n; i++) {
        count[(arr[i] - min) / range]++;
    }

    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / range;
        bucket[j][count[j]++] = arr[i];
    }

    for (i = 0; i < n; i++) {
        arr[i] = bucket[((arr[i] - min) / range)] [--count[(arr[i] - min) / range]];
    }

    for (i = 0; i < MAX; i++) {
        free(bucket[i]);
    }
    free(bucket);
}

int main() {
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}