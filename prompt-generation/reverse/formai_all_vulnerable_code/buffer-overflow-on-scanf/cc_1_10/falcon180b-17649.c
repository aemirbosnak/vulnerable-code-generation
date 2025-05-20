//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

/* Function to calculate GCD of two numbers using Euclidean Algorithm */
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

/* Function to generate two random prime numbers */
void generate_primes(int *p, int *q) {
    int i, j;
    for (i = 2; i <= MAX; i++) {
        for (j = 2; j <= MAX; j++) {
            if (i * j > MAX)
                break;
            if (gcd(i, j) == 1) {
                *p = i;
                *q = j;
                return;
            }
        }
    }
}

/* Function to calculate modular exponentiation */
int mod_pow(int base, int exponent, int mod) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent = exponent / 2;
    }
    return result;
}

/* Function to encrypt message using public key */
void encrypt(int m, int e, int n) {
    int c;
    c = mod_pow(m, e, n);
    printf("Encrypted message is: %d\n", c);
}

/* Function to decrypt message using private key */
void decrypt(int c, int d, int n) {
    int m;
    m = mod_pow(c, d, n);
    printf("Decrypted message is: %d\n", m);
}

/* Main function */
int main() {
    int p, q, n, phi, e, d;
    generate_primes(&p, &q);
    n = p * q;
    phi = (p - 1) * (q - 1);
    e = 5;
    while (gcd(e, phi)!= 1)
        e++;
    d = mod_pow(e, -1, phi);

    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    int m, choice;
    printf("Enter your choice:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter message to encrypt: ");
        scanf("%d", &m);
        encrypt(m, e, n);
    } else if (choice == 2) {
        printf("Enter message to decrypt: ");
        scanf("%d", &m);
        decrypt(m, d, n);
    }

    return 0;
}