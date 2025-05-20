//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our global variables
int p, q, n, phi, e, d;

// Define our encryption and decryption functions
int encrypt(int m) {
    int c = 1;
    for (int i = 0; i < e; i++) {
        c = (c * m) % n;
    }
    return c;
}

int decrypt(int c) {
    int m = 1;
    for (int i = 0; i < d; i++) {
        m = (m * c) % n;
    }
    return m;
}

int main() {
    // Get the two prime numbers from the user
    printf("Enter two prime numbers: ");
    scanf("%d %d", &p, &q);

    // Calculate n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Choose e such that 1 < e < phi and e is coprime to phi
    for (int i = 2; i < phi; i++) {
        if (phi % i != 0 && gcd(i, phi) == 1) {
            e = i;
            break;
        }
    }

    // Calculate d (the modular inverse of e)
    d = modinv(e, phi);

    // Display the public and private keys
    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);

    // Get the message from the user
    printf("Enter a message to encrypt: ");
    char message[100];
    scanf("%s", message);

    // Encrypt the message
    int encrypted[strlen(message)];
    for (int i = 0; i < strlen(message); i++) {
        encrypted[i] = encrypt(message[i]);
    }

    // Print the encrypted message
    printf("Encrypted message: ");
    for (int i = 0; i < strlen(message); i++) {
        printf("%d ", encrypted[i]);
    }
    printf("\n");

    // Decrypt the message
    printf("Decrypting message...\n");
    char decrypted[strlen(message)];
    for (int i = 0; i < strlen(message); i++) {
        decrypted[i] = decrypt(encrypted[i]);
    }

    // Print the decrypted message
    printf("Decrypted message: ");
    for (int i = 0; i < strlen(message); i++) {
        printf("%c", decrypted[i]);
    }
    printf("\n");

    return 0;
}

// Helper function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Helper function to find the modular inverse of a number (using the extended Euclidean algorithm)
int modinv(int a, int m) {
    int x, y;
    int g = extendedEuclid(a, m, &x, &y);
    if (g != 1) {
        printf("Error: %d is not invertible modulo %d\n", a, m);
        exit(1);
    }
    else {
        return (x % m + m) % m;
    }
}

// Helper function to find the solutions to ax + by = gcd(a, b) (for the extended Euclidean algorithm)
int extendedEuclid(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    else {
        int x1, y1;
        int gcd = extendedEuclid(b, a % b, &x1, &y1);
        *x = y1;
        *y = x1 - (a / b) * y1;
        return gcd;
    }
}