//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    long n;
    long e;
    long d;
} RSAKey;

// Function prototypes
void generateKeys(RSAKey *keyPair);
long modExponentiation(long base, long exp, long n);
long gcd(long a, long b);
long multiplicativeInverse(long e, long phi);
void RSAEncrypt(long message, RSAKey key, long *encrypted);
long RSADecrypt(long encrypted, RSAKey key, long *decrypted);

// Main Program
int main() {
    RSAKey keyPair;
    long message, encrypted, decrypted;

    printf("Generating RSA Keys...\n");
    generateKeys(&keyPair);
    
    printf("Public Key: (n = %ld, e = %ld)\n", keyPair.n, keyPair.e);
    printf("Private Key: (n = %ld, d = %ld)\n", keyPair.n, keyPair.d);

    printf("Enter a message (number) to encrypt: ");
    scanf("%ld", &message);

    RSAEncrypt(message, keyPair, &encrypted);
    printf("Encrypted message: %ld\n", encrypted);

    decrypted = RSADecrypt(encrypted, keyPair, &decrypted);
    printf("Decrypted message: %ld\n", decrypted);

    return 0;
}

void generateKeys(RSAKey *keyPair) {
    long p = 61; // prime number
    long q = 53; // prime number
    keyPair->n = p * q;
    long phi = (p - 1) * (q - 1);

    // Choosing e
    keyPair->e = 17; // Common choice for e
    
    // Calculating d
    keyPair->d = multiplicativeInverse(keyPair->e, phi);
}

long modExponentiation(long base, long exp, long n) {
    long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % n;
        }
        base = (base * base) % n;
        exp /= 2;
    }
    return result;
}

long gcd(long a, long b) {
    while (b != 0) {
        long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long multiplicativeInverse(long e, long phi) {
    long m0 = phi, t, q;
    long x0 = 0, x1 = 1;
    
    if (phi == 1) return 0;

    while (e > 1) {
        // q is quotient
        q = e / phi;
        t = phi;

        // phi is remainder now, process same as Euclid's algorithm
        phi = e % phi;
        e = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0) x1 += m0;

    return x1;
}

void RSAEncrypt(long message, RSAKey key, long *encrypted) {
    *encrypted = modExponentiation(message, key.e, key.n);
}

long RSADecrypt(long encrypted, RSAKey key, long *decrypted) {
    *decrypted = modExponentiation(encrypted, key.d, key.n);
    return *decrypted;
}