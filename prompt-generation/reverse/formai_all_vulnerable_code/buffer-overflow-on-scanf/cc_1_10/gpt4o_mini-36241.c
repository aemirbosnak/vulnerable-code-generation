//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PRIME_LIMIT 10000

int is_prime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime numbers
    if (num <= 3) return 1; // 2 and 3 are prime numbers
    if (num % 2 == 0 || num % 3 == 0) return 0; // Eliminate multiples of 2 and 3
    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

void generate_primes(int limit) {
    FILE *file = fopen("primes.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for writing.\n");
        exit(EXIT_FAILURE);
    }

    printf("Generating prime numbers up to %d...\n", limit);
    
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            fprintf(file, "%d\n", i);
            printf("%d is prime\n", i); // Display output in console
        }
    }

    fclose(file);
    printf("Prime generation completed. Check primes.txt for results.\n");
}

void display_primes_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file for reading.\n");
        exit(EXIT_FAILURE);
    }

    printf("Prime numbers read from %s:\n", filename);
    char line[50];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

int main() {
    int prime_limit = 100;

    printf("Welcome to the Synchronous Prime Number Generator!\n");
    printf("Enter the maximum limit for prime number generation (up to %d): ", MAX_PRIME_LIMIT);
    if (scanf("%d", &prime_limit) != 1) {
        fprintf(stderr, "Invalid input! Please enter a valid integer.\n");
        return EXIT_FAILURE;
    }

    if (prime_limit < 0 || prime_limit > MAX_PRIME_LIMIT) {
        fprintf(stderr, "Please enter a number in the range 0 - %d.\n", MAX_PRIME_LIMIT);
        return EXIT_FAILURE;
    }

    generate_primes(prime_limit);
    display_primes_from_file("primes.txt");

    return 0;
}