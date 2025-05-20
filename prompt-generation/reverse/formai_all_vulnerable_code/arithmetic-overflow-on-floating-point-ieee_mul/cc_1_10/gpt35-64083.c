//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

// Function to generate a prime number
int generate_prime() {
    int n, i, j, count, flag;
    printf("Generating prime number...\n");
    for (n = 2; n <= 1000; n++) {
        flag = 0;
        count = sqrt(n);
        for (i = 2; i <= count; i++) {
            if (n % i == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return n;
        }
    }
    return -1;
}

// Function to generate the public and private keys
void generate_keys(int *e, int *d, int *n) {
    int p, q, phi, gcd_val;
    // Generate two prime numbers
    p = generate_prime();
    q = generate_prime();
    // Calculate n
    *n = p * q;
    // Calculate phi(n)
    phi = (p - 1) * (q - 1);
    // Choose a number e such that 1 < e < phi(n) and e is coprime to phi(n)
    *e = 2;
    while (*e < phi) {
        gcd_val = gcd(*e, phi);
        if (gcd_val == 1) {
            break;
        }
        *e = *e + 1;
    }
    // Compute d such that d is the modular multiplicative inverse of e modulo phi(n)
    *d = 2;
    while (*d < phi) {
        gcd_val = gcd(*d, phi);
        if (gcd_val == 1) {
            if (((*e * (*d)) % phi) == 1) {
                break;
            }
        }
        *d = *d + 1;
    }
}

// Function to encrypt a message
int encrypt(int message, int e, int n) {
    int cipher = pow(message, e);
    cipher = cipher % n;
    return cipher;
}

// Function to decrypt a message
int decrypt(int cipher, int d, int n) {
    int message = pow(cipher, d);
    message = message % n;
    return message;
}

int main() {
    int e, d, n;
    printf("Generating keys...\n");
    generate_keys(&e, &d, &n);
    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);
    int message = 123; // Change this to the message you want to encrypt
    printf("Message: %d\n", message);
    int cipher = encrypt(message, e, n);
    printf("Encrypted message: %d\n", cipher);
    int decrypted_message = decrypt(cipher, d, n);
    printf("Decrypted message: %d\n", decrypted_message);
    return 0;
}