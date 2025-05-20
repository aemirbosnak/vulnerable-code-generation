//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long gcd(unsigned long a, unsigned long b) {
    while (b != 0) {
        unsigned long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

unsigned long modInverse(unsigned long a, unsigned long m) {
    a = a % m;
    for (unsigned long x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return 0; // In case no modular inverse exists
}

void generateKeys(unsigned long *e, unsigned long *d, unsigned long *n) {
    unsigned long p = 61; // A prime number
    unsigned long q = 53; // Another prime number
    *n = p * q; // n is the modulus for public and private keys
    unsigned long phi = (p - 1) * (q - 1); // Euler's totient function

    // Choosing e
    *e = 17; // A common choice for e
    while (gcd(*e, phi) != 1) {
        (*e)++;
    }

    // Calculating d
    *d = modInverse(*e, phi);
}

unsigned long encrypt(unsigned long plaintext, unsigned long e, unsigned long n) {
    unsigned long ciphertext = 1;
    for (unsigned long i = 0; i < e; i++) {
        ciphertext = (ciphertext * plaintext) % n;
    }
    return ciphertext;
}

unsigned long decrypt(unsigned long ciphertext, unsigned long d, unsigned long n) {
    unsigned long plaintext = 1;
    for (unsigned long i = 0; i < d; i++) {
        plaintext = (plaintext * ciphertext) % n;
    }
    return plaintext;
}

int main() {
    unsigned long e, d, n;
    generateKeys(&e, &d, &n);
    
    printf("Public Key: (e: %lu, n: %lu)\n", e, n);
    printf("Private Key: (d: %lu)\n", d);

    unsigned long plaintext;
    printf("Enter a plaintext number to encrypt (less than %lu): ", n);
    scanf("%lu", &plaintext);

    if (plaintext >= n) {
        printf("Plaintext must be less than modulus n.\n");
        return 1;
    }

    unsigned long ciphertext = encrypt(plaintext, e, n);
    printf("Ciphertext: %lu\n", ciphertext);

    unsigned long decrypted = decrypt(ciphertext, d, n);
    printf("Decrypted plaintext: %lu\n", decrypted);

    return 0;
}