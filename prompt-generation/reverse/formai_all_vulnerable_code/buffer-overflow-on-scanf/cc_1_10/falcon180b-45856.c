//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, sum = 0;
    clock_t start, end;

    // Get user input for n
    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    // Validate user input
    if (n <= 0) {
        printf("Error: n must be a positive integer.\n");
        return 1;
    }

    // Initialize array of n integers
    int arr[n];
    for (i = 0; i < n; i++) {
        arr[i] = i;
    }

    // Sort array using bubble sort
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Calculate sum of array elements
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Measure execution time
    start = clock();
    for (i = 0; i < 100000; i++) {
        sum += arr[i % n];
    }
    end = clock();

    // Print results
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSum of array elements: %d\n", sum);
    printf("Execution time: %.6fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}