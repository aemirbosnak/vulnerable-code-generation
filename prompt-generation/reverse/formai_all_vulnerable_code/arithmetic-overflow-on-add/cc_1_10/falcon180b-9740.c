//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

int main() {
    int arr[SIZE];
    int i, j, k, n;
    double mean, median, mode;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Generate random integers
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Calculate mean
    mean = 0;
    for (i = 0; i < n; i++) {
        mean += arr[i];
    }
    mean /= n;

    // Calculate median
    int median_index = n / 2;
    if (n % 2 == 0) {
        median = (arr[median_index - 1] + arr[median_index]) / 2;
    } else {
        median = arr[median_index];
    }

    // Calculate mode
    int mode_count = 0;
    int mode_value = arr[0];
    for (i = 0; i < n; i++) {
        int count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > mode_count) {
            mode_count = count;
            mode_value = arr[i];
        }
    }

    // Print results
    printf("Mean: %.2f\n", mean);
    printf("Median: %d\n", median);
    printf("Mode: %d\n", mode_value);

    return 0;
}