//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000

int main() {
    int i, j;
    int *arr;
    int n;
    int sum = 0;
    double avg;
    struct timespec start, end;

    // Prompt user for array size
    printf("Enter size of array: ");
    scanf("%d", &n);

    // Allocate memory for array
    arr = (int *)malloc(n * sizeof(int));

    // Prompt user for array elements
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate sum of array elements
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Calculate average of array elements
    avg = (double)sum / n;

    // Sort the array in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Print sorted array
    printf("Sorted array in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Calculate time taken to sort the array
    clock_gettime(CLOCK_REALTIME, &start);
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
    printf("Time taken to sort the array: %.3f ms\n", time_taken);

    // Free memory allocated for array
    free(arr);

    return 0;
}