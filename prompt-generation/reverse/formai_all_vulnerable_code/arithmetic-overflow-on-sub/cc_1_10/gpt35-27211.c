//FormAI DATASET v1.0 Category: Benchmarking ; Style: artistic
#include <stdio.h>
#include <time.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    clock_t start, end;
    double time_taken;

    int num = 10;

    printf("Calculating the factorial of %d...\n", num);

    start = clock(); // Start the clock

    unsigned long long result = factorial(num);

    end = clock(); // End the clock

    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Factorial of %d is %llu\n", num, result);
    printf("Time taken: %f seconds to execute\n", time_taken);

    printf("\n");

    printf("Now using recursion to calculate the factorial of %d...\n", num);

    start = clock(); // Start the clock

    result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }

    end = clock(); // End the clock

    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Factorial of %d using recursion is %llu\n", num, result);
    printf("Time taken: %f seconds to execute\n", time_taken);

    return 0;
}