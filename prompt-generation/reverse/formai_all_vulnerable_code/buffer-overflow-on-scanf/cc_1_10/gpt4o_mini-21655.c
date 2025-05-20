//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned long gcd(unsigned long a, unsigned long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

unsigned long mod_inverse(unsigned long a, unsigned long m) {
    a = a % m;
    for (unsigned long x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return 0;
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

unsigned long compute_n(unsigned long p, unsigned long q) {
    return p * q;
}

unsigned long compute_phi(unsigned long p, unsigned long q) {
    return (p - 1) * (q - 1);
}

void generate_keys(unsigned long *e, unsigned long *d, unsigned long *n) {
    unsigned long p = 61; // prime number
    unsigned long q = 53; // prime number
    *n = compute_n(p, q);
    
    unsigned long phi = compute_phi(p, q);
    *e = 17; // commonly used prime (should be coprime to phi)
    
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
    unsigned long e, d, n;
    generate_keys(&e, &d, &n);
    
    printf("Public Key: (e = %lu, n = %lu)\n", e, n);
    printf("Private Key: (d = %lu)\n", d);
    
    unsigned long plaintext;
    printf("Enter a number to encrypt: ");
    scanf("%lu", &plaintext);
    
    unsigned long ciphertext = encrypt(plaintext, e, n);
    printf("Encrypted: %lu\n", ciphertext);
    
    unsigned long decrypted = decrypt(ciphertext, d, n);
    printf("Decrypted: %lu\n", decrypted);
    
    if (decrypted == plaintext) {
        printf("Decryption successful!\n");
    } else {
        printf("Decryption failed!\n");
    }
    
    return 0;
}