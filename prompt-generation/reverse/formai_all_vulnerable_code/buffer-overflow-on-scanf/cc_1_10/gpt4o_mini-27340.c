//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0; // Numbers less than or equal to 1 are not prime
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Found a divisor, not a prime
        }
    }
    return 1; // It's a prime number!
}

void print_primes(int limit) {
    printf("🌟 Welcome to the Happy Prime Number Generator! 🌟\n");
    printf("✨ Here are the prime numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("   😊 Prime: %d\n", num);
        }
    }
    printf("🎉 All primes are happy little numbers! 🎉\n");
}

int main() {
    int limit;
    
    printf("🌼 Please enter a positive limit to generate prime numbers: ");
    if (scanf("%d", &limit) != 1 || limit < 1) {
        printf("🚫 Oops! That's not a valid positive number. Please try again! 🚫\n");
        return 1; // Exit with an error
    }
    
    print_primes(limit);
    
    // Providing options to continue generating primes
    char continue_choice;
    do {
        printf("😊 Would you like to generate more primes? (y/n): ");
        scanf(" %c", &continue_choice);
        
        if (continue_choice == 'y' || continue_choice == 'Y') {
            printf("🌼 Please enter a positive limit to generate prime numbers: ");
            if (scanf("%d", &limit) != 1 || limit < 1) {
                printf("🚫 Oops! That's not a valid positive number. Please try again! 🚫\n");
                continue;
            }
            print_primes(limit);
        } else if (continue_choice != 'n' && continue_choice != 'N') {
            printf("🚫 Invalid choice! Let's stick with yes or no next time! 🚫\n");
        }
    } while (continue_choice == 'y' || continue_choice == 'Y');

    printf("🌈 Thank you for using the Happy Prime Number Generator! Have a wonderful day! 🌈\n");
    return 0; // Successful execution
}