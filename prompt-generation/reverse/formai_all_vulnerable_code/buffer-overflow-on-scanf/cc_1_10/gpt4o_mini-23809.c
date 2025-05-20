//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// Function to compute gcd
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to compute modular exponentiation
int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to find the multiplicative inverse
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Should not reach here if inputs are valid
}

// Function to generate a random prime number (basic implementation)
int is_prime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

int generate_prime() {
    srand(time(NULL));
    int prime;
    do {
        prime = rand() % 100 + 2; // Random number between 2 and 101
    } while (!is_prime(prime));
    return prime;
}

// Function to generate RSA keys
void generate_keys(int *n, int *e, int *d) {
    int p = generate_prime();
    int q = generate_prime();
    *n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose e
    *e = 3; // A common choice for e
    while (gcd(*e, phi) != 1) {
        (*e)++;
    }

    // Calculate d
    *d = mod_inverse(*e, phi);
}

// Function to encrypt a message
int encrypt(int message, int e, int n) {
    return mod_exp(message, e, n);
}

// Function to decrypt a cipher
int decrypt(int cipher, int d, int n) {
    return mod_exp(cipher, d, n);
}

// Function to run the RSA encryption scheme
void rsa_encryption_demo() {
    int n, e, d;
    generate_keys(&n, &e, &d);
    
    printf("Public Key: (n=%d, e=%d)\n", n, e);
    printf("Private Key: d=%d\n", d);

    int message;
    printf("Enter a message (integer less than %d): ", n);
    scanf("%d", &message);

    if (message >= n) {
        printf("Message must be less than n!\n");
        return;
    }

    int cipher = encrypt(message, e, n);
    printf("Encrypted Message: %d\n", cipher);

    int decrypted_message = decrypt(cipher, d, n);
    printf("Decrypted Message: %d\n", decrypted_message);
}

int main() {
    printf("Welcome to the RSA Public-Key Cryptography Demo!\n");
    rsa_encryption_demo();
    return 0;
}