//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) {
        return false; // 0 and 1 are not prime numbers
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false; // Divisible by some number other than 1 and itself
        }
    }
    return true; // The number is prime
}

// Function to generate a list of prime numbers up to a given limit
void generate_primes(int limit, int *primes, int *count) {
    *count = 0; // Initialize count of primes found
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            primes[(*count)++] = num; // Add prime to the array and increment count
        }
    }
}

// Function to print the prime numbers list
void print_primes(int *primes, int count) {
    printf("List of Prime Numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n"); // New line after every 10 prime numbers
        }
    }
    printf("\n");
}

// Function to save the prime numbers to a file
void save_primes_to_file(int *primes, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", primes[i]);
    }
    fclose(file);
    printf("Prime numbers saved to %s\n", filename);
}

// Function to handle user input for the limit of prime numbers
int get_prime_limit() {
    int limit;
    printf("Enter the maximum number to find prime numbers: ");
    while (scanf("%d", &limit) != 1 || limit <= 1) {
        printf("Invalid input. Please enter a positive integer greater than 1: ");
        while (getchar() != '\n'); // clear the input buffer
    }
    return limit;
}

// Main function where the processing begins
int main() {
    int limit = get_prime_limit(); // Get user input for limit
    int *primes = (int *)malloc(limit * sizeof(int)); // Dynamic array to hold prime numbers
    if (primes == NULL) {
        perror("Memory allocation failed");
        return 1;
    }
    
    clock_t start_time = clock(); // Record start time for performance measurement
    int count = 0; // Count of primes found
    generate_primes(limit, primes, &count); // Generate primes
    clock_t end_time = clock(); // Record end time

    print_primes(primes, count); // Print the found primes
    
    // Save the prime numbers to a file
    char filename[30];
    snprintf(filename, sizeof(filename), "primes_up_to_%d.txt", limit);
    save_primes_to_file(primes, count, filename);

    // Calculate and display the time taken
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken to generate primes: %.2f seconds\n", time_taken);

    free(primes); // Free allocated memory
    return 0;
}