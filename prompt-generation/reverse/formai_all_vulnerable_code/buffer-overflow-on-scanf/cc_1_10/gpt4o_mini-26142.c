//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

unsigned long gcd(unsigned long a, unsigned long b) {
    while (b != 0) {
        unsigned long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

unsigned long mod_inverse(unsigned long a, unsigned long m) {
    a = a % m;
    for (unsigned long x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 1;
}

unsigned long power_mod(unsigned long base, unsigned long exp, unsigned long mod) {
    unsigned long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

void generate_keys(unsigned long *n, unsigned long *e, unsigned long *d, unsigned long p, unsigned long q) {
    *n = p * q;
    unsigned long phi = (p - 1) * (q - 1);

    *e = 3; // A common choice for e
    while (gcd(*e, phi) != 1) {
        (*e)++;
    }

    *d = mod_inverse(*e, phi);
}

unsigned long encrypt(unsigned long plaintext, unsigned long e, unsigned long n) {
    return power_mod(plaintext, e, n);
}

unsigned long decrypt(unsigned long ciphertext, unsigned long d, unsigned long n) {
    return power_mod(ciphertext, d, n);
}

int main() {
    unsigned long p = 61; // A prime number
    unsigned long q = 53; // Another prime number
    unsigned long n, e, d;

    generate_keys(&n, &e, &d, p, q);

    printf("Public Key: (E: %lu, N: %lu)\n", e, n);
    printf("Private Key: (D: %lu, N: %lu)\n", d, n);

    unsigned long plaintext;
    printf("Enter the plaintext (numeric): ");
    scanf("%lu", &plaintext);

    unsigned long encrypted = encrypt(plaintext, e, n);
    printf("Encrypted text: %lu\n", encrypted);

    unsigned long decrypted = decrypt(encrypted, d, n);
    printf("Decrypted text: %lu\n", decrypted);

    if (plaintext == decrypted) {
        printf("Success! The original and decrypted plaintext match.\n");
    } else {
        printf("Error! The original and decrypted plaintext do not match.\n");
    }

    return 0;
}