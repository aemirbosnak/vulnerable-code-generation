//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000000

// Function to calculate the nth Fibonacci number
long long int fibonacci(int n) {
    long long int fib[2] = {1, 1};
    long long int next_fib;

    for (int i = 2; i <= n; i++) {
        next_fib = fib[0] + fib[1];
        fib[0] = fib[1];
        fib[1] = next_fib;
    }

    return fib[1];
}

// Function to find the sum of even Fibonacci numbers up to a given limit
long long int sum_even_fibonacci(int limit) {
    long long int sum = 0;
    int i;

    for (i = 2; i <= limit; i++) {
        if (fibonacci(i) % 2 == 0) {
            sum += fibonacci(i);
        }
    }

    return sum;
}

int main() {
    int limit;
    long long int sum;

    // Get user input for limit
    printf("Enter the limit: ");
    scanf("%d", &limit);

    // Calculate sum of even Fibonacci numbers up to the given limit
    sum = sum_even_fibonacci(limit);

    // Print the result
    printf("The sum of even Fibonacci numbers up to %d is: %lld\n", limit, sum);

    return 0;
}