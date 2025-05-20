//Falcon-180B DATASET v1.0 Category: Error handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    int size;
    int *arr;

    // Prompt user for array size
    printf("Enter array size (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Check for invalid input
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid input. Exiting program.\n");
        exit(1);
    }

    // Allocate memory for array
    arr = (int *)malloc(size * sizeof(int));

    // Check for memory allocation failure
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        exit(1);
    }

    // Prompt user for array elements
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i])!= 1) {
            printf("Invalid input. Exiting program.\n");
            exit(1);
        }
    }

    // Calculate mean and standard deviation
    double mean = 0.0;
    double variance = 0.0;
    for (int i = 0; i < size; i++) {
        mean += arr[i];
    }
    mean /= size;

    for (int i = 0; i < size; i++) {
        variance += pow(arr[i] - mean, 2);
    }
    variance /= size;
    variance = sqrt(variance);

    // Print results
    printf("Mean: %.2f\n", mean);
    printf("Standard deviation: %.2f\n", variance);

    // Free allocated memory
    free(arr);

    return 0;
}