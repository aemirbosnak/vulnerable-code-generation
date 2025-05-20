//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_NUM 10000

// Cyberpunk-themed function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
   
    if (number % 2 == 0 || number % 3 == 0) return false;

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0)
            return false;
    }
    return true;
}

// Cyberpunk-style "Neon Matrix" to store discovered primes
void neon_matrix(int *primes, int count) {
    printf("\n*** Neon Prime Matrix ***\n");
    for (int i = 0; i < count; i++) {
        printf("| %4d ", primes[i]);
    }
    printf("|\n");
    printf("************************\n");
}

// The central function to revolutionize the prime generation
void generate_primes(int limit) {
    int *primes = (int *)malloc(MAX_NUM * sizeof(int));
    if (primes == NULL) {
        fprintf(stderr, "Insufficient memory to store primes!\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    printf("Booting up the Neon Prime Generator...\n");
    printf("Scanning the digital underbelly for primes from 1 to %d...\n", limit);

    clock_t start_time = clock();
    
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            primes[count++] = num;
            // Simulated cyberpunk visual effect
            printf("Discovered prime: %d\n", num);
            usleep(50000);  // Adding a delay for a dramatic effect
        }
    }

    clock_t end_time = clock();
    printf("Scan complete! Found %d primes.\n", count);
    printf("Operation time: %.2f seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);
    
    neon_matrix(primes, count);    
    free(primes);
}

// Main function where the cyberpunk narrative unfolds
int main() {
    // Splash screen - A brief introduction to the program
    printf("**************************************************\n");
    printf("**** Welcome to the Neon Prime Generator 3000 ****\n");
    printf("****   Your digital savior from the darkness    ****\n");
    printf("****        Scanning for the truth...          ****\n");
    printf("**************************************************\n");

    int limit;
    printf("Enter the upper limit (0 - %d) to search for primes: ", MAX_NUM);
    while (true) {
        scanf("%d", &limit);
        if (limit >= 0 && limit <= MAX_NUM) break;
        printf("Invalid input. Please enter a number between 0 and %d: ", MAX_NUM);
    }

    generate_primes(limit);

    printf("Exiting the Neon Prime Generator... Stay vigilant in the digital age!\n");
    return 0;
}