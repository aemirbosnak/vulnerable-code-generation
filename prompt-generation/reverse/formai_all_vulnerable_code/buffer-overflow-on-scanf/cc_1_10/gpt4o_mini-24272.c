//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: complete
#include <stdio.h>
#include <stdbool.h>

#define MAX_LIMIT 10000

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    
    // Check for factors from 2 to the square root of the number
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers up to a specified limit
void generatePrimes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

// Function to count and return the number of primes found
int countPrimes(int limit) {
    int count = 0;
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            count++;
        }
    }
    return count;
}

// Function to generate an array of prime numbers up to a specified limit
void generatePrimeArray(int limit, int primeArray[], int *size) {
    *size = 0;
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            primeArray[(*size)++] = num;
        }
    }
}

// Function to print prime numbers stored in an array
void printPrimeArray(int primeArray[], int size) {
    printf("Primes array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", primeArray[i]);
    }
    printf("\n");
}

// Function to find the nth prime number
int nthPrime(int n) {
    int count = 0;
    int num = 1;

    while (count < n) {
        num++;
        if (isPrime(num)) {
            count++;
        }
    }
    return num;
}

// Main function to execute the program
int main() {
    int limit = 100;
    int primeArray[MAX_LIMIT];
    int size;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Generating primes up to %d...\n", limit);
    
    // Generate and print prime numbers
    generatePrimes(limit);
    
    // Count and display number of prime numbers found
    int primeCount = countPrimes(limit);
    printf("Total number of prime numbers up to %d: %d\n", limit, primeCount);
    
    // Generate prime array and print it
    generatePrimeArray(limit, primeArray, &size);
    printPrimeArray(primeArray, size);

    // Finding the nth prime number as an example
    int n;
    printf("Enter the position of the prime number you want to find (e.g., 1 for the first prime): ");
    scanf("%d", &n);
    if (n > 0) {
        int nth_prime = nthPrime(n);
        printf("The %dth prime number is: %d\n", n, nth_prime);
    } else {
        printf("Please enter a positive integer.\n");
    }

    return 0;
}