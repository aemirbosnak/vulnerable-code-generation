//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1024

// Function to generate a random prime number
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate two large prime numbers
int* generatePrimes(int* p, int* q) {
    int max_attempts = 100;
    int attempts = 0;

    while (attempts < max_attempts) {
        *p = rand() % MAX_SIZE + 2;
        *q = rand() % MAX_SIZE + 2;
        if (isPrime(*p) && isPrime(*q)) {
            break;
        }
        attempts++;
    }

    return p;
}

// Function to calculate the modular exponentiation
int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp /= 2;
        base = (base * base) % mod;
    }
    return result;
}

// Function to encrypt the message using the public key
void encrypt(int* publicKey, int message, int* encryptedMessage) {
    *encryptedMessage = modExp(message, publicKey[0], publicKey[1]);
}

// Function to decrypt the message using the private key
void decrypt(int* privateKey, int encryptedMessage, int* decryptedMessage) {
    *decryptedMessage = modExp(encryptedMessage, privateKey[1], privateKey[0]);
}

// Main function
int main() {
    int p, q, n, phi, e, d;
    int* publicKey = (int*) malloc(2 * sizeof(int));
    int* privateKey = (int*) malloc(2 * sizeof(int));

    // Generate two large prime numbers
    generatePrimes(publicKey, privateKey);

    p = *publicKey;
    q = *privateKey;
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Choose a random number e that is coprime to phi
    e = 2;
    while (gcd(e, phi)!= 1) {
        e++;
    }

    // Calculate d such that d * e = 1 mod phi
    d = modExp(e, -1, phi);

    // Print the public and private keys
    printf("Public key: (%d, %d)\n", p, e);
    printf("Private key: (%d, %d)\n", q, d);

    // Encrypt and decrypt a message
    int message = 123;
    int encryptedMessage, decryptedMessage;
    encrypt(publicKey, message, &encryptedMessage);
    decrypt(privateKey, encryptedMessage, &decryptedMessage);

    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", encryptedMessage);
    printf("Decrypted message: %d\n", decryptedMessage);

    return 0;
}

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b!= 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}