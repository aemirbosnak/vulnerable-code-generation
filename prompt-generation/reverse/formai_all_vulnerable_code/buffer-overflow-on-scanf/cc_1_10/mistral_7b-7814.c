//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 45 // Maximum number to calculate Fibonacci sequence up to

// Helper function to calculate Fibonacci number using recursion
unsigned long long fib(unsigned int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// Function to calculate Fibonacci sequence up to given number
void fib_sequence(unsigned int num) {
    unsigned int i;

    if (num > MAX) {
        printf("Error: Number too large\n");
        exit(EXIT_FAILURE);
    }

    printf("Fibonacci sequence up to %d:\n", num);

    // Initialize first two numbers in the sequence
    unsigned long long fib_prev = 0, fib_current = 1;

    // Calculate and print the sequence up to the given number
    for (i = 0; i <= num; ++i) {
        printf("%llu ", fib_current);

        // Update the sequence values
        unsigned long long temp = fib_current;
        fib_current += fib_prev;
        fib_prev = temp;
    }

    printf("\n");
}

int main() {
    unsigned int num;

    // Input the number up to which Fibonacci sequence is to be calculated
    printf("Enter a number: ");
    scanf("%d", &num);

    fib_sequence(num);

    return EXIT_SUCCESS;
}