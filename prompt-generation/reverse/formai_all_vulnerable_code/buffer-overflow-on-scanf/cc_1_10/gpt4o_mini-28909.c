//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#define MAX_NUM 10000

void neon_sign(const char *text) {
    printf("\033[1;36m%s\033[0m\n", text);
}

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

void generate_primes(int max) {
    neon_sign("Welcome to the Cyberpunk Prime Number Generator!");
    neon_sign("Initializing the Neon Algorithm...");

    FILE *output_file = fopen("cyber_prime_output.txt", "w");
    if (output_file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fprintf(output_file, "Cyberpunk Prime Numbers up to %d:\n", max);
    
    for (int num = 2; num <= max; num++) {
        if (is_prime(num)) {
            fprintf(output_file, "%d\n", num);
            printf("\033[1;32m\nPrime Found: %d\033[0m\n", num);
            sleep(1); // Simulate processing time in the cyber world
        }
    }

    fclose(output_file);
    neon_sign("Prime Number Generation Complete!");
}

void display_intro() {
    char title[] = "Cyberpunk Prime Number Generator";
    char delimiter[] = "==============================";
    
    neon_sign(title);
    neon_sign(delimiter);
    printf("A program forged from the remnants of the neon-lit nights.\n");
    printf("Summoning prime numbers to aid your digital escapades.\n\n");
}

int main(int argc, char *argv[]) {
    display_intro();

    int upper_limit;

    printf("Enter the upper limit for prime number generation (up to %d): ", MAX_NUM);
    scanf("%d", &upper_limit);

    if (upper_limit > MAX_NUM || upper_limit < 1) {
        neon_sign("Error: Please enter a valid number between 1 and 10000.");
        return EXIT_FAILURE;
    }

    generate_primes(upper_limit);

    return EXIT_SUCCESS;
}