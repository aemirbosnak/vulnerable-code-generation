//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: modular
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    if (num % 2 == 0) {
        return false;
    }

    int divisor = 3;
    while (divisor * divisor <= num) {
        if (num % divisor == 0) {
            return false;
        }
        divisor += 2;

        if (num % divisor == 0) {
            return false;
        }
        divisor += 4;
    }

    return true;
}

// Function to generate prime numbers up to a given limit
void generate_primes(int limit) {
    int count = 0;
    int num = 2;

    printf("Prime numbers up to %d:\n", limit);

    while (num <= limit) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\nTotal number of prime numbers up to %d: %d\n", limit, count);
}

int main() {
    int limit;

    printf("Enter the limit to generate prime numbers up to: ");
    scanf("%d", &limit);

    generate_primes(limit);

    return 0;
}