//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: funny
#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

// Declare the mighty scepter - I mean, the array to hold our prime numbers
int primes[MAX];
int prime_count = 0;

// Function prototypes
void generate_primes(int limit);
bool is_prime(int number);
void display_primes();

// The main event - where all the magic happens
int main() {
    int limit;

    // Welcome message
    printf("🎩 Welcome to the Prime Number Circus! 🎪\n");
    printf("Today, our mission is to uncover the elusive prime numbers up to a certain limit.\n");
    printf("Please enter the maximum number you'd like our Houdini Primes to escape from: ");
    
    // Get the limit from the user
    scanf("%d", &limit);

    // Let's start the magical generator!
    generate_primes(limit);

    // Show off our prime numbers
    display_primes();

    printf("🎉 Thanks for visiting the Prime Number Circus! Come back anytime for more magical numbers! 🎉\n");
    return 0;
}

// Function to generate primes up to a given limit
void generate_primes(int limit) {
    // Starting a countdown to the biggest reveal
    printf("🤹‍♂️ Generating primes up to %d...\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes[prime_count++] = i; // "Catch" the prime number!
            printf("🎈 Found a prime: %d!\n", i);
        }
    }
}

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) return false; // Division by zero or negative numbers are not allowed, this isn't a horror show!
    if (number == 2) return true; // 2 is the star of our show - the only even prime!

    // Check divisibility starting from 3, in our distinctly bizarre way
    for (int i = 3; i * i <= number; i += 2) { // Skipping even numbers
        if (number % i == 0) {
            printf("💥 %d got blasted by %d! Not a prime!\n", number, i);
            return false; // A fail in our fun house!
        }
    }
    // If it survived all that, it’s a magical prime!
    return true;
}

// Function to display the prime numbers
void display_primes() {
    printf("\n🎉 The Magical Prime Number Show! 🎉\n");
    printf("Here are all the primes that we caught today:\n");

    // We like to show them off in style
    for (int i = 0; i < prime_count; i++) {
        printf("🌟 %d ", primes[i]);
        // Adding a little flair with a clap sound every 10 primes
        if ((i + 1) % 10 == 0) {
            printf("👏\n");
        }
    }
    printf("\n🎆 And that’s our grand display of primes! 🎆\n");
}