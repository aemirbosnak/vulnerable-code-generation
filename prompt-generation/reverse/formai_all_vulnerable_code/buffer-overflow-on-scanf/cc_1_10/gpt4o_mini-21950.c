//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false; // 1 and negative numbers are not prime
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // Found a divisor, so it's not prime
        }
    }
    return true; // It's prime!
}

// Function to print prime numbers up to a given limit
void generate_primes(int limit) {
    printf("🎉 Woohoo! Let's find all the prime numbers up to %d! 🎉\n\n", limit);
    
    // Check every number from 2 to the limit
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("🌟 Found a prime number: %d 🌟\n", num);
        }
    }
    printf("\n🎊 All done! Did you enjoy the journey through primes? 🎊\n");
}

// Main function to get user input and start the process
int main() {
    int limit;
    
    // Cheerfully ask for user input
    printf("👋 Hey there! Welcome to the Prime Number Generator! 👋\n");
    printf("Please enter a positive integer as the upper limit: ");
    
    // Input validation loop
    while (true) {
        scanf("%d", &limit);
        if (limit > 1) {
            break; // We got a valid input!
        } else {
            printf("Oops! That's not a valid positive integer. Try again! 😊\n");
            printf("Please enter a positive integer as the upper limit: ");
        }
    }
    
    // Generate the prime numbers
    generate_primes(limit);
    
    return 0; // Show's over, folks! ✌️
}