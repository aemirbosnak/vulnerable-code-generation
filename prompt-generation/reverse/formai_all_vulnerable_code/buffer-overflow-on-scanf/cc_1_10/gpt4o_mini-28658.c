//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_PRIMES 100

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to calculate the geometric mean
double geometric_mean(int primes[], int count) {
    double product = 1.0;
    for (int i = 0; i < count; i++) {
        product *= primes[i];
    }
    return pow(product, 1.0 / count);
}

// Function to create a simple ASCII art representation of primes
void print_ascii_art(int primes[], int count) {
    printf("\nASCII Art Representation of Prime Numbers:\n");
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < primes[i]; j++) {
            printf("*");
        }
        printf(" %d\n", primes[i]);
    }
}

// Main function to execute the program
int main() {
    int primes[MAX_PRIMES];
    int count = 0;
    int userInput;

    printf("Welcome to the Prime Number Rainbow Generator!\n");
    printf("Please enter a positive integer to find prime numbers up to that limit: ");
    scanf("%d", &userInput);

    // Generate prime numbers up to userInput
    for (int num = 2; num <= userInput && count < MAX_PRIMES; num++) {
        if (is_prime(num)) {
            primes[count++] = num;
            printf("Found prime: %d\n", num);
        }
    }

    // Compute and display the geometric mean of found primes
    if (count > 0) {
        double geo_mean = geometric_mean(primes, count);
        printf("\nThe geometric mean of the found prime numbers is: %.2f\n", geo_mean);
    } else {
        printf("\nNo prime numbers found within the given limit.\n");
    }

    // Print ASCII art representation
    print_ascii_art(primes, count);

    // Brave farewell from the program
    printf("\nThank you for using the Prime Number Rainbow Generator! Embrace the power of mathematics!\n");
    
    return 0;
}