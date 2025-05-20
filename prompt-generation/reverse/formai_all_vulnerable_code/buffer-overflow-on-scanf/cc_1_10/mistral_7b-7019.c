//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

#define MAX_SEQUENCE_SIZE 62

// Function to calculate nth Fibonacci number using dynamic programming approach
unsigned long long fib(unsigned int n) {
    unsigned long long fib_sequence[MAX_SEQUENCE_SIZE];

    fib_sequence[0] = 0;
    fib_sequence[1] = 1;

    if (n > MAX_SEQUENCE_SIZE) {
        fprintf(stderr, "Invalid sequence size\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 2; i <= n; i++) {
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
    }

    return fib_sequence[n];
}

// Function to print Fibonacci sequence of given length
void print_fibonacci_sequence(unsigned int sequence_length) {
    printf("Fibonacci sequence of length %d:\n", sequence_length);

    for (unsigned int i = 0; i < sequence_length; i++) {
        printf("%llu ", fib(i));
    }

    printf("\n");
}

// Function to check if given number is a prime number
int is_prime(unsigned int number) {
    if (number <= 1) {
        return 0;
    }

    for (unsigned int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to find the first prime number in Fibonacci sequence of given length
unsigned int find_first_prime(unsigned int sequence_length) {
    unsigned int fib_sequence[MAX_SEQUENCE_SIZE];
    unsigned int prime_number = 0;

    fib_sequence[0] = 0;
    fib_sequence[1] = 1;

    for (unsigned int i = 2; i <= sequence_length; i++) {
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];

        if (is_prime(fib_sequence[i])) {
            prime_number = fib_sequence[i];
            break;
        }
    }

    return prime_number;
}

int main() {
    unsigned int sequence_length;

    printf("Enter the length of the Fibonacci sequence: ");
    scanf("%d", &sequence_length);

    print_fibonacci_sequence(sequence_length);

    unsigned int prime_number = find_first_prime(sequence_length);

    if (prime_number != 0) {
        printf("The first prime number in the Fibonacci sequence of length %d is %d\n", sequence_length, prime_number);
    } else {
        printf("The Fibonacci sequence of length %d does not contain any prime numbers\n", sequence_length);
    }

    return EXIT_SUCCESS;
}