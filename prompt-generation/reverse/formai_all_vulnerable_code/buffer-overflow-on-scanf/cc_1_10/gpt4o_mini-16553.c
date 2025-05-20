//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PRIME 10000
#define BUFFER_SIZE 1024

typedef struct {
    int e;  // Public exponent
    int n;  // Modulus
} PublicKey;

typedef struct {
    int d;  // Private exponent
    int n;  // Modulus
} PrivateKey;

unsigned long gcd(unsigned long a, unsigned long b) {
    while (b != 0) {
        unsigned long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

unsigned long mod_inverse(unsigned long a, unsigned long m) {
    for (unsigned long x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;  // Should not reach here
}

int is_prime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

int generate_prime(int lower, int upper) {
    int prime = lower;
    while (!is_prime(prime)) {
        prime++;
        if (prime > upper) {
            return -1;  // No prime found in range
        }
    }
    return prime;
}

void generate_keys(PublicKey* pub_key, PrivateKey* priv_key) {
    int p = generate_prime(2, MAX_PRIME);
    int q = generate_prime(p + 1, MAX_PRIME);
    
    if (p == -1 || q == -1) {
        fprintf(stderr, "Failed to generate primes.\n");
        exit(EXIT_FAILURE);
    }

    int n = p * q;
    int phi = (p - 1) * (q - 1);
    
    // Choose e
    int e = 3;  // Common choice for e
    while (gcd(e, phi) != 1) {
        e += 2;  // Increment e to find a valid one
    }
    
    int d = mod_inverse(e, phi);

    pub_key->e = e;
    pub_key->n = n;
    priv_key->d = d;
    priv_key->n = n;
}

unsigned long encrypt(unsigned long message, PublicKey* pub_key) {
    unsigned long result = 1;
    for (int i = 0; i < pub_key->e; i++) {
        result = (result * message) % pub_key->n;
    }
    return result;
}

unsigned long decrypt(unsigned long ciphertext, PrivateKey* priv_key) {
    unsigned long result = 1;
    for (int i = 0; i < priv_key->d; i++) {
        result = (result * ciphertext) % priv_key->n;
    }
    return result;
}

void display_keys(PublicKey* pub_key, PrivateKey* priv_key) {
    printf("Public Key: (e: %d, n: %d)\n", pub_key->e, pub_key->n);
    printf("Private Key: (d: %d, n: %d)\n", priv_key->d, priv_key->n);
}

int main() {
    PublicKey pub_key;
    PrivateKey priv_key;

    generate_keys(&pub_key, &priv_key);
    display_keys(&pub_key, &priv_key);

    unsigned long message;
    printf("Enter a message (integer) to encrypt: ");
    scanf("%lu", &message);

    unsigned long encrypted = encrypt(message, &pub_key);
    printf("Encrypted message: %lu\n", encrypted);

    unsigned long decrypted = decrypt(encrypted, &priv_key);
    printf("Decrypted message: %lu\n", decrypted);

    return 0;
}