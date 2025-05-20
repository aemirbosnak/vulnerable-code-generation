//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: shape shifting
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_NUM 100000000 // Maximum number to check for prime
#define MAX_PRIMES 100000 // Maximum number of primes to generate

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    int i;
    for (i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers
void generate_primes(int count, int start_num) {
    int num = start_num;
    int primes_generated = 0;
    while (primes_generated < count) {
        if (is_prime(num)) {
            printf("%d ", num);
            primes_generated++;
        }
        num++;
    }
}

int main() {
    int num_primes;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &num_primes);
    if (num_primes > MAX_PRIMES) {
        printf("Error: Maximum number of primes is %d\n", MAX_PRIMES);
        return 1;
    }
    int start_num;
    printf("Enter the starting number: ");
    scanf("%d", &start_num);
    if (start_num <= 1) {
        printf("Error: Starting number must be greater than 1\n");
        return 1;
    }
    generate_primes(num_primes, start_num);
    return 0;
}