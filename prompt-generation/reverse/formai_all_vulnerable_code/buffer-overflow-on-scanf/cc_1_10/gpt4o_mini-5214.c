//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to generate and print all primes in the given range
void generate_primes(int start, int end) {
    if (start < 2) start = 2; // Primes start from 2
    printf("Prime numbers between %d and %d:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int start, end;
    char choice;

    printf("Welcome to the Prime Number Generator!\n");
    printf("This program allows you to generate prime numbers in a specified range.\n");
    
    do {
        printf("\nEnter the start of the range: ");
        scanf("%d", &start);
        printf("Enter the end of the range: ");
        scanf("%d", &end);

        // Validate range
        if (start > end) {
            printf("Error: Starting number must be less than or equal to ending number.\n");
            continue;
        }

        generate_primes(start, end);
        
        printf("Would you like to generate another range of primes? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume newline character

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Prime Number Generator!\n");
    return 0;
}