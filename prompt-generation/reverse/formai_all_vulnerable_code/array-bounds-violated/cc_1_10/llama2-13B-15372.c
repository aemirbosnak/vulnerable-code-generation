//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the first duplicate element in the array
    int dup = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr[dup]) {
            dup = i;
        }
    }
    printf("First duplicate element: %d\n", arr[dup]);

    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Maximum element: %d\n", max);

    // Find the minimum element in the array
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Minimum element: %d\n", min);

    // Find the sum of all elements in the array
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Sum of all elements: %d\n", sum);

    // Find the product of all elements in the array
    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= arr[i];
    }
    printf("Product of all elements: %d\n", product);

    return 0;
}