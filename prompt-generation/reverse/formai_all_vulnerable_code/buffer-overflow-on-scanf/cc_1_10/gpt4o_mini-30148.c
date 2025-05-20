//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int is_prime(int number, int divisor) {
    // Base case: if number is less than 2, it's not prime
    if (number < 2) {
        return 0;
    }
    // If divisor is greater than the square root of the number, we know it's prime
    if (divisor * divisor > number) {
        return 1;
    }
    // Check divisibility
    if (number % divisor == 0) {
        return 0; // Not prime
    }
    // Recursive case: check the next divisor
    return is_prime(number, divisor + 1);
}

void generate_primes(int limit, int current, int *primes, int *index) {
    // Base case: if current exceeds the limit, stop recursion
    if (current > limit) {
        return;
    }
    // Check if the current number is prime
    if (is_prime(current, 2)) {
        primes[*index] = current; // Store the prime number
        (*index)++; // Increment the index for the next prime
    }
    // Recur for the next number
    generate_primes(limit, current + 1, primes, index);
}

int main() {
    int limit;
    
    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &limit);
    
    // Allocate memory for storing prime numbers, a rough estimate
    int *primes = (int *)malloc(limit * sizeof(int));
    if (primes == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    int index = 0; // To track the number of primes found

    // Generate prime numbers recursively
    generate_primes(limit, 2, primes, &index);
    
    // Print the generated prime numbers
    printf("Prime numbers up to %d are:\n", limit);
    for (int i = 0; i < index; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
    
    // Free the allocated memory
    free(primes);
    
    return 0;
}