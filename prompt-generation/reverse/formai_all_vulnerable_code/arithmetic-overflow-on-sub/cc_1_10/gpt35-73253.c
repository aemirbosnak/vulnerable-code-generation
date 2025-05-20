//FormAI DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A function that calculates the factorial of an integer
int factorial(int num) {
    int res = 1;
    for (int i = 1; i <= num; i++) {
        res *= i;
    }
    return res;
}

int main() {
    // Initialize variables
    int num, res1, res2, res3;
    clock_t start, stop;

    // Prompt user for input
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Test 1: Calculate the factorial of the integer
    start = clock();
    res1 = factorial(num);
    stop = clock();
    double time1 = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("Factorial: %d\n", res1);
    printf("Time taken: %f seconds\n\n", time1);

    // Test 2: Calculate the power of 2 to the integer
    start = clock();
    res2 = 1 << num;
    stop = clock();
    double time2 = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("Power of 2: %d\n", res2);
    printf("Time taken: %f seconds\n\n", time2);

    // Test 3: Calculate the sum of the integers up to the input integer
    start = clock();
    res3 = 0;
    for (int i = 1; i <= num; i++) {
        res3 += i;
    }
    stop = clock();
    double time3 = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("Sum of integers: %d\n", res3);
    printf("Time taken: %f seconds\n\n", time3);

    // Output the benchmarking results
    printf("Benchmarking results:\n");
    printf("Test 1 (factorial) took %f seconds\n", time1);
    printf("Test 2 (power of 2) took %f seconds\n", time2);
    printf("Test 3 (sum of integers) took %f seconds\n", time3);

    return 0;
}