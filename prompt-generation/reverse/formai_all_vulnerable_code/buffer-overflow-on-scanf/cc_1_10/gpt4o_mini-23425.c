//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayPrimes(int limit, int *is_prime) {
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void savePrimesToFile(int limit, int *is_prime) {
    FILE *file = fopen("primes.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            fprintf(file, "%d\n", i);
        }
    }
    fclose(file);
    printf("Prime numbers saved to primes.txt.\n");
}

void sieveOfEratosthenes(int limit) {
    int *is_prime = malloc((limit + 1) * sizeof(int));
    
    if (is_prime == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    memset(is_prime, 1, (limit + 1) * sizeof(int)); // Initialize all numbers as prime
    is_prime[0] = is_prime[1] = 0; // 0 and 1 are not prime numbers

    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = 0; // Marking multiples of p as non-prime
            }
        }
    }

    // Display results
    char choice[10];
    printf("Do you want to (d)isplay or (s)ave the prime numbers? ");
    scanf("%s", choice);

    if (strcmp(choice, "d") == 0) {
        displayPrimes(limit, is_prime);
    } else if (strcmp(choice, "s") == 0) {
        savePrimesToFile(limit, is_prime);
    } else {
        printf("Invalid choice! Please enter either 'd' or 's'.\n");
    }

    free(is_prime);
}

int main() {
    int limit;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Please enter the upper limit for generating prime numbers: ");
    if (scanf("%d", &limit) != 1 || limit < 2) {
        printf("Error: Please enter a valid integer greater than 1.\n");
        return 1; // Exit if input is not valid
    }

    sieveOfEratosthenes(limit);
    printf("Thank you for using the Prime Number Generator!\n");
    
    return 0;
}