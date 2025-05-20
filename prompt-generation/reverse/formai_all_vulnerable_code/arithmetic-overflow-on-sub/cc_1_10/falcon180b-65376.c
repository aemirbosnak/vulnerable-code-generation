//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, sum = 0;
    clock_t start, end;
    double cpu_time_used;

    // take input from user
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // initialize array
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = i;
    }

    // sort array using bubble sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // calculate sum of array elements
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    // measure cpu time used
    start = clock();
    for (i = 0; i < 1000000; i++) {
        sum += i;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // print results
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Sum of array elements: %d\n", sum);
    printf("CPU time used (in seconds): %.6f\n", cpu_time_used);

    return 0;
}