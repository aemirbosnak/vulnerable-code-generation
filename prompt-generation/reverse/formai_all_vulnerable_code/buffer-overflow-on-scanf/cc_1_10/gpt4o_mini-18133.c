//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_primes(int *primes, int count) {
    printf("\nGenerated Prime Numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
        // Visualization by adding a special character for every ten primes
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int is_prime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime
    if (num <= 3) return 1; // 2 and 3 are prime
    if (num % 2 == 0 || num % 3 == 0) return 0; // eliminate multiples of 2 and 3
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0; // eliminate other multiples
    }
    return 1;
}

int* generate_primes(int limit, int *count) {
    int *primes = malloc(limit * sizeof(int)); // Dynamic memory allocation for prime numbers array
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE); // Handle memory allocation failure
    }

    *count = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes[*count] = i;
            (*count)++;
        }
    }
    return primes;
}

void display_intro() {
    printf("=======================================\n");
    printf("   Welcome to the Prime Number Generator \n");
    printf("=======================================\n");
    printf("This program generates all prime numbers up to a specified limit.\n");
    printf("Let’s dive into the world of primes!\n\n");
}

int main() {
    int limit;
    int count;
    int *primes;

    display_intro();

    printf("Enter the upper limit for prime generation: ");
    scanf("%d", &limit);

    if (limit < 2) {
        printf("Please enter a number greater than or equal to 2.\n");
        return 1; // Early exit if the limit is invalid
    }

    primes = generate_primes(limit, &count); // Generate primes

    print_primes(primes, count);

    // Clean up dynamic memory allocation
    free(primes);
    printf("Thank you for using the Prime Number Generator! Goodbye!\n");

    return 0;
}