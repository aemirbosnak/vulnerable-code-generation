//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int n) {
    if (n < 2) {
        return 0;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }

    return gcd(b % a, a);
}

// Function to generate keys
void generate_keys(int p, int q, int *n, int *e, int *d) {
    *n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose a value for e that is relatively prime to phi
    for (*e = 2; *e < phi; (*e)++) {
        if (gcd(*e, phi) == 1) {
            break;
        }
    }

    // Compute d such that ed = 1 (mod phi)
    int k = 1;
    while (1) {
        if (((k * phi) + 1) % *e == 0) {
            *d = ((k * phi) + 1) / *e;
            break;
        }

        k++;
    }
}

// Function to encrypt a message
void encrypt(int m, int e, int n, int *c) {
    int result = 1;

    for (int i = 0; i < e; i++) {
        result = (result * m) % n;
    }

    *c = result;
}

// Function to decrypt a ciphertext
void decrypt(int c, int d, int n, int *m) {
    int result = 1;

    for (int i = 0; i < d; i++) {
        result = (result * c) % n;
    }

    *m = result;
}

int main() {
    int p, q, n, e, d, m, c;

    // Generate two random prime numbers
    do {
        p = rand() % 100 + 1;
    } while (!is_prime(p));

    do {
        q = rand() % 100 + 1;
    } while (!is_prime(q));

    // Generate public and private keys
    generate_keys(p, q, &n, &e, &d);

    printf("Public key: (%d, %d)\n", n, e);
    printf("Private key: (%d, %d)\n", n, d);

    // Get input from user
    printf("Enter a message to encrypt: ");
    scanf("%d", &m);

    // Encrypt the message
    encrypt(m, e, n, &c);

    printf("Encrypted message: %d\n", c);

    // Decrypt the message
    decrypt(c, d, n, &m);

    printf("Decrypted message: %d\n", m);

    return 0;
}