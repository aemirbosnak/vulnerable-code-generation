//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

// Function to check if a given number is prime or not
int isPrime(int);

// Function to generate prime numbers
void generatePrimes(int, int);

int main() {
    int start, end;

    // Taking input from user
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);

    // Generating prime numbers between start and end
    generatePrimes(start, end);

    return 0;
}

// Function to check if a given number is prime or not
int isPrime(int num) {
    int i;

    // 1 is not a prime number
    if (num == 1)
        return 0;

    // 2 is a prime number
    if (num == 2)
        return 1;

    // Check for even numbers
    if (num % 2 == 0)
        return 0;

    // Check for odd numbers
    for (i = 3; i <= num / 2; i += 2) {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

// Function to generate prime numbers
void generatePrimes(int start, int end) {
    int i, j, count = 0;

    // Loop through all numbers between start and end
    for (i = start; i <= end; i++) {
        // Check if the number is prime
        if (isPrime(i) == 1) {
            // Print the prime number
            printf("%d ", i);
            count++;

            // Check if the maximum number of primes has been reached
            if (count == 200) {
                printf("\nMaximum number of primes (200) reached!\n");
                break;
            }
        }
    }
}