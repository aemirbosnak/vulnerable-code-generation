//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function prototypes
void generate_primes(int limit);
void save_primes_to_file(int limit);
void display_menu();
bool is_prime(int number);

int main() {
    int choice, limit;

    // Displaying menu and accepting user choice
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the limit for prime number generation: ");
                scanf("%d", &limit);
                generate_primes(limit);
                break;
            case 2:
                printf("Enter the limit for saving prime numbers to a file: ");
                scanf("%d", &limit);
                save_primes_to_file(limit);
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

// Function to display menu options
void display_menu() {
    printf("\n--- Prime Number Generator ---\n");
    printf("1. Generate Prime Numbers\n");
    printf("2. Save Prime Numbers to File\n");
    printf("3. Exit\n");
}

// Function to generate prime numbers up to a specified limit
void generate_primes(int limit) {
    if (limit < 2) {
        printf("There are no prime numbers less than 2.\n");
        return;
    }

    bool *isPrime = malloc((limit + 1) * sizeof(bool));
    for (int i = 0; i <= limit; i++) {
        isPrime[i] = true; // Initialize all entries as true
    }
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes

    // Start timing the generation
    clock_t start = clock();

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                isPrime[multiple] = false; // Mark multiples as non-prime
            }
        }
    }

    // Print the prime numbers
    printf("Prime numbers up to %d:\n", limit);
    for (int number = 2; number <= limit; number++) {
        if (isPrime[number]) {
            printf("%d ", number);
        }
    }
    printf("\n");

    // Calculate and display the time taken
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to generate primes: %.6f seconds\n", time_spent);

    free(isPrime); // Free allocated memory
}

// Function to save prime numbers to a file
void save_primes_to_file(int limit) {
    if (limit < 2) {
        printf("There are no prime numbers less than 2 to save.\n");
        return;
    }

    bool *isPrime = malloc((limit + 1) * sizeof(bool));
    for (int i = 0; i <= limit; i++) {
        isPrime[i] = true; // Initialize all entries as true
    }
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes

    // Generating prime numbers using Sieve of Eratosthenes
    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                isPrime[multiple] = false; // Mark multiples as non-prime
            }
        }
    }

    // Saving prime numbers to a file
    FILE *file = fopen("primes.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        free(isPrime);
        return;
    }

    fprintf(file, "Prime numbers up to %d:\n", limit);
    for (int number = 2; number <= limit; number++) {
        if (isPrime[number]) {
            fprintf(file, "%d ", number);
        }
    }
    fprintf(file, "\n");

    fclose(file); // Close the file
    printf("Prime numbers saved to 'primes.txt'.\n");

    free(isPrime); // Free allocated memory
}