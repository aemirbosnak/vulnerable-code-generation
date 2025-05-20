//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIMIT 10000 

// Function declarations
void print_welcome_message();
void print_goodbye_message();
bool is_prime(int number);
void generate_primes(int limit);
void print_primes(int *primes, int count);

int main() {
    print_welcome_message();

    int limit;
    printf("Enter the upper limit up to which you want to generate prime numbers (max %d): ", MAX_LIMIT);
    
    // User input validation loop
    while (true) {
        if (scanf("%d", &limit) != 1 || limit < 1 || limit > MAX_LIMIT) {
            printf("Invalid input! Please enter a number between 1 and %d: ", MAX_LIMIT);
            // Clear the input buffer
            while(getchar() != '\n'); 
            continue;
        }
        break;
    }

    generate_primes(limit);
    print_goodbye_message();

    return 0;
}

// Welcome message to greet the user
void print_welcome_message() {
    printf("*********************************************\n");
    printf("       Welcome to the Prime Number Generator!\n");
    printf("*********************************************\n");
}

// Goodbye message to bid farewell to the user
void print_goodbye_message() {
    printf("*********************************************\n");
    printf("         Thank you for using the generator! \n");
    printf("*********************************************\n");
}

// Function to determine if a number is prime
bool is_prime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false; 

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate and print prime numbers up to a given limit
void generate_primes(int limit) {
    int *primes = (int *)malloc(sizeof(int) * limit);
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;

    printf("Generating prime numbers up to %d:\n", limit);

    for (int i = 1; i <= limit; i++) {
        if (is_prime(i)) {
            primes[count++] = i;
        }
    }

    print_primes(primes, count);

    free(primes); // Free allocated memory
}

// Function to print the generated prime numbers
void print_primes(int *primes, int count) {
    if (count == 0) {
        printf("No prime numbers found in this range.\n");
        return;
    }

    printf("Total prime numbers found: %d\n", count);
    printf("Prime numbers:\n");
    
    for (int i = 0; i < count; i++) {
        if ((i + 1) % 10 == 0) {
            printf("%d\n", primes[i]); // New line after every 10 primes
        } else {
            printf("%d ", primes[i]); // Print on same line
        }
    }
    if (count % 10 != 0) {
        printf("\n"); // New line if not a multiple of 10
    }
}