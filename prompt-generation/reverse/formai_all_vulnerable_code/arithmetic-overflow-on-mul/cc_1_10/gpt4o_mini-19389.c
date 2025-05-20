//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_PRIMES 1000

// Function prototypes
int is_prime(int num);
int generate_random_number(int lower, int upper);
void generate_keys(int *e, int *d, int *n);
int encrypt(int message, int e, int n);
int decrypt(int cipher, int d, int n);
int gcd(int a, int b);
int mod_inverse(int a, int m);

int main() {
    int p, q, n, e, d;
    srand(time(0));  // Seed the random number generator

    // Generate two distinct random prime numbers
    do {
        p = generate_random_number(2, MAX_PRIMES);
    } while (!is_prime(p));

    do {
        q = generate_random_number(2, MAX_PRIMES);
    } while (!is_prime(q) || p == q);

    // Calculate n
    n = p * q;

    // Generate public and private keys
    generate_keys(&e, &d, n);

    // Display generated keys
    printf("Public Key: (e=%d, n=%d)\n", e, n);
    printf("Private Key: (d=%d, n=%d)\n", d, n);

    // Demonstrate encryption and decryption
    int message;
    printf("Enter a message to encrypt (0 to %d): ", n - 1);
    scanf("%d", &message);

    int cipher = encrypt(message, e, n);
    printf("Encrypted message: %d\n", cipher);

    int decrypted_message = decrypt(cipher, d, n);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

// Function to generate a random number between lower and upper
int generate_random_number(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

// Function to generate public and private keys
void generate_keys(int *e, int *d, int *n) {
    int phi = (*n - (sqrt(*n) * 2));  // Euler's Totient Function approximation
    *e = 3;  // Smallest prime

    // Ensure e and phi are coprime
    while (gcd(*e, phi) != 1) {
        *e += 2;
    }

    *d = mod_inverse(*e, phi);
}

// Function to encrypt a message
int encrypt(int message, int e, int n) {
    int result = 1;
    for (int i = 0; i < e; i++) {
        result = (result * message) % n;
    }
    return result;
}

// Function to decrypt a cipher
int decrypt(int cipher, int d, int n) {
    int result = 1;
    for (int i = 0; i < d; i++) {
        result = (result * cipher) % n;
    }
    return result;
}

// Function to compute the greatest common divisor
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to find modular inverse using Extended Euclidean Algorithm
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}