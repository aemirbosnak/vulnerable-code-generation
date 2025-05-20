//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to find gcd of a and b
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find modular inverse of a under modulo m
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

// Function to perform modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
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

// Function to generate prime numbers (naive approach)
int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

// Function to generate keys
void generateKeys(int *e, int *d, long long *n) {
    int p, q;

    // Simple prime number generation
    srand(time(0));
    do {
        p = rand() % 50 + 1; // Random number between 1 and 50
    } while (!isPrime(p));

    do {
        q = rand() % 50 + 1; // Random number between 1 and 50
    } while (!isPrime(q) || q == p);

    *n = p * q;
    long long phi = (p - 1) * (q - 1);
    
    // Choose e
    for (*e = 2; *e < phi; (*e)++) {
        if (gcd(*e, phi) == 1)
            break;
    }

    // Compute d
    *d = modInverse(*e, phi);
}

// Function to encrypt a message
long long encrypt(long long message, int e, long long n) {
    return modExp(message, e, n);
}

// Function to decrypt a message
long long decrypt(long long cipherText, int d, long long n) {
    return modExp(cipherText, d, n);
}

int main() {
    int e, d;
    long long n;
    generateKeys(&e, &d, &n);

    printf("Public Key: (e: %d, n: %lld)\n", e, n);
    printf("Private Key: (d: %d, n: %lld)\n", d, n);

    long long message;
    printf("Enter message to encrypt (numeric only): ");
    scanf("%lld", &message);

    long long cipherText = encrypt(message, e, n);
    printf("Encrypted message: %lld\n", cipherText);

    long long decryptedMessage = decrypt(cipherText, d, n);
    printf("Decrypted message: %lld\n", decryptedMessage);

    return 0;
}