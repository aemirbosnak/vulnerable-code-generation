//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PRIME 100000 // Set a maximum limit for prime generation.

void print_welcome_message() {
    printf("--------------------------------------------------\n");
    printf("Welcome to the Prime Number Generator!\n");
    printf("This program generates all prime numbers up to %d.\n", MAX_PRIME);
    printf("--------------------------------------------------\n");
}

bool is_prime(int number) {
    if (number <= 1) return false; // Negative numbers, 0 and 1 are not prime numbers.
    if (number <= 3) return true; // 2 and 3 are prime numbers.

    // Check for multiples of 2 and 3
    if (number % 2 == 0 || number % 3 == 0) return false;

    // Use 6k ± 1 rule to check for prime numbers
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void generate_primes(int limit) {
    printf("Generating prime numbers up to %d...\n", limit);
   
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
        }
    }
    printf("\nPrime number generation finished!\n");
}

void save_primes_to_file(int limit) {
    FILE *file = fopen("primes.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            fprintf(file, "%d\n", num);
        }
    }
    fclose(file);
    printf("Prime numbers have been saved to primes.txt!\n");
}

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Generate Prime Numbers\n");
    printf("2. Save Prime Numbers to File\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    print_welcome_message();

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generate_primes(MAX_PRIME);
                break;
            case 2:
                save_primes_to_file(MAX_PRIME);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}