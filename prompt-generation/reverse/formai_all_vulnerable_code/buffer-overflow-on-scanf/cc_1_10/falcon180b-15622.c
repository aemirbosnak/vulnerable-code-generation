//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define a function to calculate the factorial of a number
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    // Initialize variables
    int n;
    double sum = 0;
    clock_t start_time, end_time;
    double cpu_time_used;

    // Prompt user for input
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Calculate the sum of the reciprocals of odd numbers up to the given number
    for (int i = 1; i <= n; i++) {
        if (i % 2!= 0) {
            sum += 1.0 / i;
        }
    }

    // Calculate the factorial of the given number
    long long fact = factorial(n);

    // Print the results
    printf("The sum of the reciprocals of odd numbers up to %d is: %.2f\n", n, sum);
    printf("The factorial of %d is: %lld\n", n, fact);

    // Measure the CPU time used by the program
    start_time = clock();
    for (int i = 1; i <= n; i++) {
        if (i % 2!= 0) {
            sum += 1.0 / i;
        }
    }
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("CPU time used: %.2f seconds\n", cpu_time_used);

    return 0;
}