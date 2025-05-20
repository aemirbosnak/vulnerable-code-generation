//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute the GCD of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// Function to compute the modular inverse using Extended Euclidean Algorithm
int modInverse(int a, int m) {
    int m0 = m, y = 0, x = 1;
    if (m == 1) return 0;
    
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }

    if (x < 0) x += m0;

    return x;
}

// Function to generate keys
void generateKeys(int *e, int *d, int *n) {
    // For simplicity, we are using small prime numbers p=61, q=53
    int p = 61, q = 53;
    *n = p * q; // n = p * q
    int phi = (p - 1) * (q - 1); // Euler's Totient Function

    // Choosing e
    *e = 17; // You can select a prime number less than phi and coprime to it
    while (gcd(*e, phi) != 1) {
        (*e)++;
    }

    // Computing d
    *d = modInverse(*e, phi);
}

// Function to encrypt the message
int encrypt(int message, int e, int n) {
    int result = 1;
    for (int i = 0; i < e; i++) {
        result = (result * message) % n;
    }
    return result; // Returns the encrypted message
}

// Function to decrypt the message
int decrypt(int encryptedMessage, int d, int n) {
    int result = 1;
    for (int i = 0; i < d; i++) {
        result = (result * encryptedMessage) % n;
    }
    return result; // Returns the original message
}

int main() {
    printf("Grateful Public Key Algorithm Implementation\n");
    
    int e, d, n;
    generateKeys(&e, &d, &n);

    printf("Generated Keys:\n");
    printf("Public Key (e, n): (%d, %d)\n", e, n);
    printf("Private Key (d): %d\n", d);

    int message;
    printf("Enter a message (integer value): ");
    scanf("%d", &message);

    printf("Original Message: %d\n", message);
    
    int encryptedMessage = encrypt(message, e, n);
    printf("Encrypted Message: %d\n", encryptedMessage);
    
    int decryptedMessage = decrypt(encryptedMessage, d, n);
    printf("Decrypted Message: %d\n", decryptedMessage);
    
    if (message == decryptedMessage) {
        printf("Decryption successful! Thank you for using this Public Key Algorithm!\n");
    } else {
        printf("Decryption failed! But we are grateful for the learning experience.\n");
    }

    return 0;
}