//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multivariable
// Import required libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Define global variables
int p, q, n, phi, e, d;

// Define function prototypes
bool isPrime(int);
int gcd(int, int);
int generatePublicKey(int, int);
int generatePrivateKey(int, int);

// Main function
int main() {
    printf("Enter two prime numbers: ");
    scanf("%d %d", &p, &q);

    // Check if entered values are prime
    if (!isPrime(p) || !isPrime(q)) {
        printf("Both values must be prime. Program terminated.\n");
        return 0;
    }

    // Calculate values of n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Generate value of e for public key
    e = generatePublicKey(n, phi);

    // Generate value of d for private key
    d = generatePrivateKey(e, phi);

    printf("\nPublic key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    return 0;
}

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to calculate greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to generate value of e for public key
int generatePublicKey(int n, int phi) {
    int e;
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) {
            break;
        }
    }
    return e;
}

// Function to generate value of d for private key
int generatePrivateKey(int e, int phi) {
    int k = 1;
    int d;
    while (1) {
        k += phi;
        if (k % e == 0) {
            d = k / e;
            break;
        }
    }
    return d;
}