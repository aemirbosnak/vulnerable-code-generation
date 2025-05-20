//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000000

int main() {
    int i, j, n, sum = 0;
    clock_t start, end;
    double cpu_time_used;

    int *arr = (int *)malloc(MAX_SIZE * sizeof(int));

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    srand(time(NULL));

    // Fill the array with random integers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array using merge sort
    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n - size; left += 2 * size) {
            int mid = left + size - 1;
            int right = mid + size - 1;

            if (mid >= n - 1) {
                break;
            }

            int temp[size];

            for (int k = left; k <= mid; k++) {
                temp[k - left] = arr[k];
            }

            for (int k = mid + 1; k <= right; k++) {
                temp[k - left] = arr[k];
            }

            int i = left;
            int j = mid + 1;

            for (int k = left; k <= right; k++) {
                if (temp[i - left] <= temp[j - left]) {
                    arr[k] = temp[i - left];
                    i++;
                } else {
                    arr[k] = temp[j - left];
                    j++;
                }
            }
        }
    }

    // Print the sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}