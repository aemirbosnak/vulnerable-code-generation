//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MODULUS 0x7FFFFFFF
#define PRIME1 0x10001
#define PRIME2 0x10009

// Function to calculate GCD
int gcd(int a, int b) {
    int temp;
    while (b!= 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate modular exponentiation
int powmod(int base, int exponent, int mod) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

// Function to generate public and private keys
void generate_keys() {
    int p, q, n, phi, e, d;
    int gcd_result;

    // Generate two large prime numbers
    p = rand() % MODULUS + 1;
    q = rand() % MODULUS + 1;

    // Calculate n = p * q
    n = p * q;

    // Calculate phi = (p-1) * (q-1)
    phi = (p - 1) * (q - 1);

    // Choose an integer e such that 1 < e < phi and e is coprime to phi
    e = rand() % phi + 1;
    while (gcd(e, phi)!= 1) {
        e = rand() % phi + 1;
    }

    // Calculate d such that d * e = 1 mod phi
    d = powmod(e, -1, phi);

    // Print the public and private keys
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);
}

// Function to encrypt a message using the public key
void encrypt(int message, int e, int n) {
    int ciphertext = powmod(message, e, n);
    printf("Encrypted message: %d\n", ciphertext);
}

// Function to decrypt a message using the private key
void decrypt(int ciphertext, int d, int n) {
    int message = powmod(ciphertext, d, n);
    printf("Decrypted message: %d\n", message);
}

int main() {
    generate_keys();
    int message = 123;
    encrypt(message, 5, 35);
    decrypt(message, 29, 35);
    return 0;
}