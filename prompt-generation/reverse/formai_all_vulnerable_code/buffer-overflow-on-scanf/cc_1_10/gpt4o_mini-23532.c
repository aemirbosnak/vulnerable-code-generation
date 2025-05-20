//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

/* Function prototypes */
long long gcd(long long a, long long b);
long long modInverse(long long a, long long m);
void generateKeys(long long *n, long long *e, long long *d, long long p, long long q);
long long encrypt(long long msg, long long e, long long n);
long long decrypt(long long enc_msg, long long d, long long n);

int main() {
    long long p, q, n, e, d;
    long long message, encrypted_message, decrypted_message;

    // Seed for randomness
    srand(time(NULL));

    // Choose two prime numbers
    p = 61; // A prime number
    q = 53; // Another prime number
    printf("Chosen prime numbers:\np = %lld\nq = %lld\n", p, q);

    // Generate public and private keys
    generateKeys(&n, &e, &d, p, q);
    printf("Public Key (n, e): (%lld, %lld)\n", n, e);
    printf("Private Key (d): %lld\n", d);

    // Input a message to encrypt
    printf("Enter a message (numeric - 0 to 999): ");
    scanf("%lld", &message);

    // Encrypt the message
    encrypted_message = encrypt(message, e, n);
    printf("Encrypted Message: %lld\n", encrypted_message);

    // Decrypt the message
    decrypted_message = decrypt(encrypted_message, d, n);
    printf("Decrypted Message: %lld\n", decrypted_message);

    // Check if the decryption was successful
    if (message == decrypted_message) {
        printf("Success! The decrypted message matches the original message.\n");
    } else {
        printf("Decryption failed! The decrypted message does not match.\n");
    }

    return 0;
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        // q is the quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as Euclid's algorithm
        m = a % m;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

void generateKeys(long long *n, long long *e, long long *d, long long p, long long q) {
    *n = p * q; // n is the modulus for the public and private keys
    long long phi = (p - 1) * (q - 1); // Euler's totient function

    // Choose e such that 1 < e < phi and gcd(e, phi) = 1
    *e = 65537; // Commonly used prime number for e
    if (gcd(*e, phi) != 1) {
        printf("Error: e must be coprime to phi.\n");
        exit(1);
    }

    // Calculate d, the modular multiplicative inverse of e mod phi
    *d = modInverse(*e, phi);
}

long long encrypt(long long msg, long long e, long long n) {
    long long res = 1;
    for (long long i = 0; i < e; i++) {
        res = (res * msg) % n; // (msg^e) mod n
    }
    return res;
}

long long decrypt(long long enc_msg, long long d, long long n) {
    long long res = 1;
    for (long long i = 0; i < d; i++) {
        res = (res * enc_msg) % n; // (enc_msg^d) mod n
    }
    return res;
}