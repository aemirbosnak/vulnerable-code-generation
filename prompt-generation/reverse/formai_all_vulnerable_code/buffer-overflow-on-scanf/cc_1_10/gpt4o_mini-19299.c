//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_prime(int num) {
    printf("%d ", num);
}

bool is_prime(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime numbers
    if (n <= 3) return true;  // 2 and 3 are prime numbers

    // Check for even number or multiples of 3
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void generate_primes(int limit) {
    printf("Woo hoo! Generating prime numbers up to %d!\n", limit);
    printf("Primes are: ");
    
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            print_prime(i);
        }
    }
    
    printf("\nWhat a magnificent list of primes we've generated!\n");
}

int main() {
    int limit;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Enter the upper limit to which you'd like to generate prime numbers: ");
    scanf("%d", &limit);

    while(limit < 2) {
        printf("Please enter a limit greater than or equal to 2. Try again: ");
        scanf("%d", &limit);
    }

    generate_primes(limit);

    printf("Fantastic! You've just witnessed the magic of prime numbers!\n");
    printf("Keep exploring the world of mathematics! Until next time!\n");

    return 0;
}