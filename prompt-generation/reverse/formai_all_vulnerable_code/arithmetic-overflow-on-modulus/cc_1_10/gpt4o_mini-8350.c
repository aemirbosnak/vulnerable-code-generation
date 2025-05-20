//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <gmp.h>

#define BUFFER_SIZE 1024

// Function to compute the GCD
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// Function to find modular inverse
int mod_inverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

// Function for RSA key generation
void generate_keys(int *e, int *d, int *n) {
    int p = 61; // A prime number
    int q = 53; // Another prime number
    *n = p * q; // n is the modulus for the keys
    int phi = (p - 1) * (q - 1); // Euler's totient

    // Choosing e
    *e = 17; // A common choice for e

    // Computing d, the modular multiplicative inverse of e
    *d = mod_inverse(*e, phi);
}

// Encryption function
int encrypt(int plaintext, int e, int n) {
    int ciphertext = 1;
    for (int i = 0; i < e; i++)
        ciphertext = (ciphertext * plaintext) % n;
    return ciphertext;
}

// Decryption function
int decrypt(int ciphertext, int d, int n) {
    int plaintext = 1;
    for (int i = 0; i < d; i++)
        plaintext = (plaintext * ciphertext) % n;
    return plaintext;
}

// Simulated Server 1: Key Generation
void key_generation() {
    int e, d, n;
    generate_keys(&e, &d, &n);
    printf("Public Key: (e: %d, n: %d)\n", e, n);
    printf("Private Key: (d: %d)\n", d);
}

// Simulated Server 2: Encryption
void encryption(int e, int n) {
    int plaintext;
    printf("Enter plaintext (integer): ");
    scanf("%d", &plaintext);
    int ciphertext = encrypt(plaintext, e, n);
    printf("Ciphertext: %d\n", ciphertext);
}

// Simulated Server 3: Decryption
void decryption(int d, int n) {
    int ciphertext;
    printf("Enter ciphertext (integer): ");
    scanf("%d", &ciphertext);
    int decrypted = decrypt(ciphertext, d, n);
    printf("Decrypted plaintext: %d\n", decrypted);
}

// Main function simulating different servers
int main() {
    int choice, e, d, n;
    
    printf("Welcome to Distributed RSA Implementation\n");
    printf("1. Key Generation\n");
    printf("2. Encryption\n");
    printf("3. Decryption\n");
    printf("Choose an option (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            key_generation();
            break;

        case 2:
            printf("Please enter public keys from Server 1:\n");
            printf("e: ");
            scanf("%d", &e);
            printf("n: ");
            scanf("%d", &n);
            encryption(e, n);
            break;

        case 3:
            printf("Please enter private key from Server 1:\n");
            printf("d: ");
            scanf("%d", &d);
            printf("n: ");
            scanf("%d", &n);
            decryption(d, n);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}