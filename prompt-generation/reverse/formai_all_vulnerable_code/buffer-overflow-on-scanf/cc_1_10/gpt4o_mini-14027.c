//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

// Function prototype declarations
bool is_prime(int num);
void generate_primes(int N);
void record_prime_statistics(int *primes, int count);
void print_statistics(const int *primes, int count);

#define MAX_PRIME_COUNT 1000

int main() {
    int N;

    printf("Welcome to the Prime Number Generator!\n");
    printf("How many prime numbers would you like to generate? (max %d): ", MAX_PRIME_COUNT);
    scanf("%d", &N);

    if (N > MAX_PRIME_COUNT || N <= 0) {
        printf("Please enter a valid number of primes to generate (1 - %d).\n", MAX_PRIME_COUNT);
        return 1;
    }

    generate_primes(N);

    return 0;
}

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

// Function to generate N prime numbers
void generate_primes(int N) {
    int *primes = (int*)malloc(N * sizeof(int));
    if (primes == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int count = 0;
    int number = 2; // Starting number to check for primes

    // Prime generation loop
    while (count < N) {
        if (is_prime(number)) {
            primes[count] = number;
            count++;
        }
        number++;
    }

    printf("Generated %d prime numbers:\n", N);
    print_statistics(primes, count);

    free(primes);
}

// Function to record prime statistics
void record_prime_statistics(int *primes, int count) {
    FILE *file = fopen("prime_statistics.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(1);
    }

    fprintf(file, "Total Prime Count: %d\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(file, "Prime %d: %d\n", i + 1, primes[i]);
    }
    fclose(file);
    printf("Statistics recorded in 'prime_statistics.txt'\n");
}

// Function to print statistics of generated primes
void print_statistics(const int *primes, int count) {
    int min = primes[0];
    int max = primes[count - 1];
    double sum = 0.0, mean, variance = 0.0, stddev;

    // Calculate the sum
    for (int i = 0; i < count; i++) {
        sum += primes[i];
    }
    
    // Calculate mean
    mean = sum / count;

    // Calculate variance
    for (int i = 0; i < count; i++) {
        variance += pow(primes[i] - mean, 2);
    }
    variance /= count;

    // Calculate standard deviation
    stddev = sqrt(variance);

    printf("Statistics of Generated Primes:\n");
    printf("Minimum Prime: %d\n", min);
    printf("Maximum Prime: %d\n", max);
    printf("Mean Prime: %.2f\n", mean);
    printf("Standard Deviation: %.2f\n", stddev);

    // Record to file
    record_prime_statistics((int *)primes, count);
}