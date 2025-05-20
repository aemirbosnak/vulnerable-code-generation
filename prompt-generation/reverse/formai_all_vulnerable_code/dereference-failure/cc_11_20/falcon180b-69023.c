//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

int main() {
    int n, i, j, max, min;
    int *arr;
    int *bucket;
    int *sorted_arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));
    bucket = (int *) malloc((MAX_SIZE + 1) * sizeof(int));
    sorted_arr = (int *) malloc(n * sizeof(int));

    if (arr == NULL || bucket == NULL || sorted_arr == NULL) {
        printf("Memory error!\n");
        exit(0);
    }

    printf("Enter the elements: ");
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

    max += 1;
    min -= 1;

    for (i = 0; i <= max; i++) {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    for (i = 1; i <= max; i++) {
        bucket[i] += bucket[i-1];
    }

    for (i = n - 1; i >= 0; i--) {
        sorted_arr[bucket[arr[i] - min] - 1] = arr[i];
        bucket[arr[i] - min]--;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", sorted_arr[i]);
    }

    free(arr);
    free(bucket);
    free(sorted_arr);

    return 0;
}