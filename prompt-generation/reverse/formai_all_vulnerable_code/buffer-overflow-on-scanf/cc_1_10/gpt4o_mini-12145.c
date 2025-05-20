//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long gcd(unsigned long a, unsigned long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

unsigned long mod_inverse(unsigned long a, unsigned long m) {
    for (unsigned long x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 0;
}

void generate_keys(unsigned long *e, unsigned long *d, unsigned long *n) {
    unsigned long p = 61; // First prime number
    unsigned long q = 53; // Second prime number
    *n = p * q; // n is the modulus for the public and private keys
    unsigned long phi = (p - 1) * (q - 1); // Euler's totient

    // Choose e such that 1 < e < phi and gcd(e, phi) = 1
    *e = 17; // Commonly used value for e
    
    // Calculate d, the modular inverse of e mod phi
    *d = mod_inverse(*e, phi);
}

unsigned long encrypt(unsigned long message, unsigned long e, unsigned long n) {
    unsigned long cipher = 1;
    for (unsigned long i = 0; i < e; i++) {
        cipher = (cipher * message) % n; // Perform encryption
    }
    return cipher;
}

unsigned long decrypt(unsigned long cipher, unsigned long d, unsigned long n) {
    unsigned long decrypted = 1;
    for (unsigned long i = 0; i < d; i++) {
        decrypted = (decrypted * cipher) % n; // Perform decryption
    }
    return decrypted;
}

int main() {
    unsigned long e, d, n;
    generate_keys(&e, &d, &n);

    printf("Public Key: (e: %lu, n: %lu)\n", e, n);
    printf("Private Key: (d: %lu, n: %lu)\n", d, n);

    unsigned long message;
    printf("Enter a message to encrypt (numerical value): ");
    scanf("%lu", &message);

    unsigned long cipher = encrypt(message, e, n);
    printf("Encrypted message: %lu\n", cipher);

    unsigned long decrypted_message = decrypt(cipher, d, n);
    printf("Decrypted message: %lu\n", decrypted_message);

    return 0;
}