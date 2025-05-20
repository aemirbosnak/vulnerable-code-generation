//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mathematical
/* This program implements a unique compression algorithm using mathematical operations and data structures. */

#include <stdio.h>
#include <stdlib.h>

// Function to calculate the length of an integer
int intLen(int n) {
    int count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

// Function to calculate the sum of all digits in an integer
int digitSum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Main function
int main() {
    // Initialize variables
    int n, i, j, k, sum, len;
    int *arr;
    int **matrix;

    // Get user input
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for array and matrix
    arr = (int *) malloc(n * sizeof(int));
    matrix = (int **) malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matrix[i] = (int *) malloc(n * sizeof(int));
    }

    // Fill array with user input
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Fill matrix with the sum of all digits in each pair of array elements
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum = digitSum(arr[i]) + digitSum(arr[j]);
            matrix[i][j] = sum;
        }
    }

    // Print the original array
    printf("\nOriginal array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Print the compressed array
    printf("\nCompressed array: ");
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < n; j++) {
            len = intLen(matrix[i][j]);
            k = 1;
            while (len > 1) {
                k *= 10;
                len--;
            }
            sum += matrix[i][j] * k;
        }
        printf("%d ", sum);
    }

    // Free memory
    free(arr);
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}