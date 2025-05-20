//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100
#define MAX_VALUE 1000

int bucket_sort(int arr[], int n) {
    int i, j;
    int *bucket[MAX_VALUE];

    for (i = 0; i < MAX_VALUE; i++) {
        bucket[i] = (int *)malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++) {
        bucket[(int)arr[i] / 10] = realloc(bucket[(int)arr[i] / 10], sizeof(int) * (i + 1));
        bucket[(int)arr[i] / 10][i] = arr[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_VALUE; j++) {
            if (bucket[j]!= NULL) {
                arr[i] = bucket[j][i];
            }
        }
    }

    for (i = 0; i < MAX_VALUE; i++) {
        free(bucket[i]);
    }

    return 0;
}

int main() {
    int arr[MAX_SIZE], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}