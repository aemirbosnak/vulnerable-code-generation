//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    long long n; // modulus
    long long e; // public exponent
    long long d; // private exponent
} RSAKey;

// Function to compute gcd of two numbers
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to find modular inverse using Extended Euclidean Algorithm
long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to generate a prime number using randomness
long long randomPrime() {
    long long num;
    int isPrime;

    srand(time(NULL));
    
    do {
        num = rand() % 100; // Limit for simplicity
        if (num < 2) continue; // Skip numbers less than 2
        isPrime = 1;
        for (long long i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = 0;
                break;
            }
        }
    } while (!isPrime);

    return num;
}

// Function to generate RSA keypair
RSAKey generateKeys() {
    long long p = randomPrime();
    long long q = randomPrime();
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);
    
    long long e = 3; // commonly used small exponent
    while (gcd(e, phi) != 1) {
        e += 2; // Increment e until it's coprime with phi
    }

    long long d = modInverse(e, phi);

    RSAKey key = { n, e, d };
    return key;
}

// Function to encrypt plaintext message
long long encrypt(long long plaintext, RSAKey publicKey) {
    long long cipher = 1;
    for (long long i = 0; i < publicKey.e; i++) {
        cipher = (cipher * plaintext) % publicKey.n;
    }
    return cipher;
}

// Function to decrypt cipher message
long long decrypt(long long cipherText, RSAKey privateKey) {
    long long plaintext = 1;
    for (long long i = 0; i < privateKey.d; i++) {
        plaintext = (plaintext * cipherText) % privateKey.n;
    }
    return plaintext;
}

// Main function to demonstrate RSA encryption and decryption
int main() {
    RSAKey key = generateKeys();
    
    printf("Generated RSA Key:\n");
    printf("Public Key (n, e): (%lld, %lld)\n", key.n, key.e);
    printf("Private Key (n, d): (%lld, %lld)\n\n", key.n, key.d);

    long long plaintext;
    printf("Enter a number to encrypt (0 - %lld): ", key.n);
    scanf("%lld", &plaintext);

    if (plaintext < 0 || plaintext >= key.n) {
        printf("Plaintext must be in the range [0, %lld]. Exiting...\n", key.n);
        return 1;
    }

    long long cipherText = encrypt(plaintext, key);
    printf("Encrypted Message: %lld\n", cipherText);

    long long decryptedText = decrypt(cipherText, key);
    printf("Decrypted Message: %lld\n", decryptedText);

    return 0;
}