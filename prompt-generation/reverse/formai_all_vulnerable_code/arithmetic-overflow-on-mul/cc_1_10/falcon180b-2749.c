//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1024

typedef struct {
    int n;
    int e;
    int d;
} RSA;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int power(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent /= 2;
        base = (base * base) % modulus;
    }
    return result;
}

void generate_keys(RSA *key) {
    int p, q, phi, d;
    int i;
    do {
        p = rand() % MAX_LENGTH + 1;
        q = rand() % MAX_LENGTH + 1;
    } while (gcd(p, q)!= 1);
    key->n = p * q;
    key->e = 65537;
    phi = (p - 1) * (q - 1);
    for (i = 2; i * i <= phi; i++) {
        if (phi % i == 0) {
            d = power(i, phi / i, phi);
            break;
        }
    }
    key->d = d;
}

int encrypt(int plaintext, RSA *key) {
    return power(plaintext, key->e, key->n);
}

int decrypt(int ciphertext, RSA *key) {
    return power(ciphertext, key->d, key->n);
}

int main() {
    RSA key;
    generate_keys(&key);
    int message = 123456;
    int ciphertext = encrypt(message, &key);
    int decrypted = decrypt(ciphertext, &key);
    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", ciphertext);
    printf("Decrypted message: %d\n", decrypted);
    return 0;
}