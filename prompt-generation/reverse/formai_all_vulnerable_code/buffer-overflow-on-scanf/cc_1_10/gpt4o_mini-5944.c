//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void print_welcome_message() {
    printf("*********************************\n");
    printf("Welcome to the Mystical Prime Quest!\n");
    printf("Journey through numbers and discover the elusive primes!\n");
    printf("*********************************\n\n");
}

bool is_prime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}

void generate_primes(int limit) {
    printf("To the great adventurers who seek primes!\n");
    printf("We shall discover all prime numbers up to %d:\n", limit);
    printf("------------------------------------------------\n");
    
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("Found a prime: %d\n", num);
        }
    }
    
    printf("The journey through numbers has come to an end.\n");
    printf("You've uncovered all the primes up to %d!\n", limit);
    printf("Thank you for embarking on this mystical quest!\n");
}

int get_user_limit() {
    int limit;
    printf("Enter an upper limit (the realm of numbers to explore): ");
    while (true) {
        scanf("%d", &limit);
        if (limit >= 2) break; 
        printf("Please enter a number greater than or equal to 2: ");
    }
    return limit;
}

void farewell_message() {
    printf("\nAs you depart from this mystical realm, remember:\n");
    printf("Primes are the gems in the forest of numbers,\n");
    printf("Shining bright and rare, they're waiting to be discovered.\n");
    printf("May your adventures continue onward and upward!\n");
}

int main() {
    print_welcome_message();
    int limit = get_user_limit();
    generate_primes(limit);
    farewell_message();
    
    return 0;
}