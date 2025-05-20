//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Function declaration
int is_prime(int num);
void generate_primes(int count);

int main() {
    int choice, count;

    printf("Welcome to the Prime Number Generator!\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Generate Prime Numbers\n");
        printf("2. Exit\n");
        printf("Select an option (1 or 2): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many prime numbers would you like to generate? ");
                scanf("%d", &count);
                if (count > 0) {
                    generate_primes(count);
                } else {
                    printf("Please enter a positive integer.\n");
                }
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select 1 or 2.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0; // numbers less than or equal to 1 are not prime
    if (num <= 3) return 1; // 2 and 3 are prime
    
    // Check for divisibility by 2 and 3
    if (num % 2 == 0 || num % 3 == 0) return 0;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }

    return 1; // num is prime
}

// Function to generate prime numbers
void generate_primes(int count) {
    int found_primes = 0;
    int num = 2; // Starting from the first prime number

    printf("Generating the first %d prime numbers...\n", count);
    
    while (found_primes < count) {
        if (is_prime(num)) {
            printf("%d ", num);
            found_primes++;
        }
        num++;
    }
    printf("\nPrime number generation complete!\n");
}