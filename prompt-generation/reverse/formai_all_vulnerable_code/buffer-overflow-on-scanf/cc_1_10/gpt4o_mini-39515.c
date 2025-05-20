//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1)
        return false;  // 0 and 1 are not prime numbers
    if (num <= 3)
        return true;   // 2 and 3 are prime numbers

    // Check for divisibility starting from 2 up to the square root of num
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;  // Found a divisor, so it's not prime
    }
    return true;  // No divisors found, thus it's prime
}

// Function to generate and print prime numbers up to a given limit
void generate_primes(int limit) {
    printf("     * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("                    Prime Numbers Up to %d\n", limit);
    printf("     * * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("                          ");
    
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num);  // Print the prime number
        }
    }
    
    printf("\n     * * * * * * * * * * * * * * * * * * * * * * * *\n");
}

// Main function to handle user input and initiate prime number generation
int main() {
    int limit;
    printf("Enter the limit up to which you want to generate prime numbers: ");
    scanf("%d", &limit);

    if (limit < 2) {
        printf("There are no prime numbers less than 2!\n");
        return 1;  // Exit with an error code
    }

    // Generate and print prime numbers
    generate_primes(limit);

    return 0;  // Exit successfully
}