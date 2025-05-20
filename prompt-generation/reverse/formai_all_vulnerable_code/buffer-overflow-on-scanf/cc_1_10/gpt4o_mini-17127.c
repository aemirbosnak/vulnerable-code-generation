//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) 
        return 0; // 0 and 1 are not prime numbers
    if (num <= 3) 
        return 1; // 2 and 3 are prime numbers
    if (num % 2 == 0 || num % 3 == 0) 
        return 0; // Eliminate multiples of 2 and 3
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0; // Eliminate multiples of 6k +/- 1
    }
    return 1; // The number is prime
}

// Function to generate and print prime numbers up to a limit
void generate_primes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to get user input with validation
int get_user_input() {
    int num;
    char term;
    
    printf("Enter a positive integer as the limit for prime number generation: ");
    
    while (1) {
        if (scanf("%d%c", &num, &term) != 2 || term != '\n' || num <= 0) {
            // Clear stdin buffer for invalid input
            while ((term = getchar()) != '\n' && term != EOF);
            printf("Invalid input. Please enter a positive integer: ");
        } else {
            break;
        }
    }
    
    return num;
}

int main() {
    printf("Welcome to the Prime Number Generator!\n");
    
    // Get user input while ensuring it is a positive integer
    int limit = get_user_input();
    
    // Generate and display the prime numbers
    generate_primes(limit);
    
    printf("Thank you for using the Prime Number Generator!\n");
    return 0;
}