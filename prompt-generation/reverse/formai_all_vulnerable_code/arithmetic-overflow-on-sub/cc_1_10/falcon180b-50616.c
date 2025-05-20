//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

// Function to calculate factorial
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Initialize array with n elements
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    // Sort the array using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Calculate factorial of n using iterative approach
    clock_t start = clock();
    long long iterative_factorial = 1;
    for (int i = 2; i <= n; i++) {
        iterative_factorial *= i;
    }
    clock_t end = clock();
    double iterative_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate factorial of n using recursive approach
    clock_t start2 = clock();
    long long recursive_factorial = factorial(n);
    clock_t end2 = clock();
    double recursive_time = (double)(end2 - start2) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the factorials and their times
    printf("\nIterative factorial: %lld\nIterative time: %lf seconds\n", iterative_factorial, iterative_time);
    printf("Recursive factorial: %lld\nRecursive time: %lf seconds\n", recursive_factorial, recursive_time);

    return 0;
}