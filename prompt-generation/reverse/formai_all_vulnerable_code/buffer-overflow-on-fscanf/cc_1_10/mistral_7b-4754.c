//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: romantic
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// Function to check if a number is prime
bool is_prime(int num) {
    int i;
    for (i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers and write to file
void generate_primes(FILE *file, int limit) {
    int num, i;
    for (num = 2; num < limit; num++) {
        if (is_prime(num)) {
            fprintf(file, "%d\n", num);
        }
    }
}

// Function to read prime numbers from file and print in romantic style
void print_romantic_primes(FILE *file) {
    int prime, i;
    bool first = true;

    printf("Once upon a time, in a land of numbers,\n");
    printf("Lived the most enchanting primes, so they say,\n");
    printf("Let us explore, and let our hearts play,\n");
    printf("With these captivating numbers, so fine and gay.\n");

    while (fscanf(file, "%d", &prime) != EOF) {
        if (first) {
            first = false;
            printf("First among them, %d, a true delight,\n", prime);
        } else {
            printf("And then came %d, to capture our sight,\n", prime);
        }
    }

    printf("Together they dance, an eternal waltz,\n");
    printf("In the realm of numbers, a prime romance, a dazzling twirl!\n");
}

int main() {
    int limit = 101;
    FILE *file = fopen("prime_numbers.txt", "w");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Creating prime numbers...\n");
    generate_primes(file, limit);
    fclose(file);

    printf("Prime numbers generated successfully! Let's explore them in romantic style.\n");
    file = fopen("prime_numbers.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    print_romantic_primes(file);

    fclose(file);
    return 0;
}