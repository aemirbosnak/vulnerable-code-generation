//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    if (n <= 3) return true;  // 2 and 3 are prime numbers
    if (n % 2 == 0 || n % 3 == 0) return false; // Eliminate multiples of 2 and 3
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false; // Check for factors
        }
    }
    return true; // If no factors found, it's prime
}

// Function to generate and print prime numbers up to a specific limit
void generate_primes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i); // Print the prime number
        }
    }
    printf("\n");
}

// Function to get user input
int get_user_input() {
    int limit;
    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &limit); // Get the limit from the user
    return limit;
}

// Main function to execute the program
int main() {
    printf("****************************************\n");
    printf("*       Prime Number Generator         *\n");
    printf("****************************************\n");

    int limit = get_user_input();
    
    if (limit < 0) {
        printf("Please enter a positive integer.\n");
        return 1; // Exit on invalid input
    }

    generate_primes(limit);

    printf("Thank you for using the Prime Number Generator!\n");
    return 0; // Exit successfully
}