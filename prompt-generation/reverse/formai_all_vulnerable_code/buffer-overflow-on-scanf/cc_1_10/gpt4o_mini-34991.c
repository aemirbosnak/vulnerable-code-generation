//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void generate_primes(int count) {
    int found = 0;
    int number = 2; // Start from the first prime number
    printf("Let's explore prime numbers together!\n");
    printf("We are looking for the first %d prime numbers:\n", count);
    while (found < count) {
        if (is_prime(number)) {
            printf("%d ", number);
            found++;
        }
        number++;
    }
    printf("\nIsn't it fascinating how primes appear in unexpected places?\n");
}

int main() {
    int count;

    printf("Greetings, curious mathematician!\n");
    printf("How many prime numbers would you like to see? ");
    if (scanf("%d", &count) != 1 || count <= 0) {
        printf("Oh, that seems to be an invalid number...\n");
        printf("Let me suggest a positive integer instead. Let's try with 10.\n");
        count = 10; // default value
    }

    generate_primes(count);

    printf("Did you know, prime numbers are used in modern encryption?\n");
    printf("For cryptography, large prime numbers play a crucial role.\n");
    printf("It's almost magical how something so simple can help protect our information!\n");
    printf("If you want a barrier against adversaries, here are some large prime candidates:\n");

    // Generate and display larger primes for curiosity
    for (int i = 0; i < 3; i++) {
        int large_prime = 1000 + i * 200; // Example; adjust as needed
        printf("Is %d a prime number? Let's find out...\n", large_prime);
        if (is_prime(large_prime)) {
            printf("Yes, %d is a prime number!\n", large_prime);
        } else {
            printf("No, %d is not a prime number.\n", large_prime);
        }
    }
    
    printf("Thank you for exploring the world of prime numbers with me!\n");
    printf("Would you like to learn more about mathematics? There are infinite wonders to discover!\n");

    return 0;
}