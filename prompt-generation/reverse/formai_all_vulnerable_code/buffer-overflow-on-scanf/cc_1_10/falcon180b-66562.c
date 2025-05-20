//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define prime numbers
#define P 101
#define Q 103

// define function to calculate greatest common divisor
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// define function to calculate modular inverse
int mod_inv(int a, int m) {
    int x, y;
    int g = gcd(a, m);
    if (g == 1) {
        return 1;
    } else {
        x = (a / g) % m;
        y = (m - 1) / g;
        return (x * y) % m;
    }
}

// define function to generate public and private keys
void generate_keys(int *public_key, int *private_key) {
    int p = P, q = Q;
    int n = p * q;
    int phi_n = (p - 1) * (q - 1);
    int e = 17; // public key exponent
    int d = mod_inv(e, phi_n); // private key exponent
    *public_key = e;
    *private_key = d;
}

// define function to encrypt message
void encrypt(int public_key, int message, int *encrypted_message) {
    int n = (public_key - 1) * (public_key - 1);
    int m = message % n;
    int c = m * public_key % n;
    *encrypted_message = c;
}

// define function to decrypt message
void decrypt(int private_key, int encrypted_message, int *decrypted_message) {
    int n = (private_key - 1) * (private_key - 1);
    int m = encrypted_message % n;
    int c = m * private_key % n;
    *decrypted_message = c;
}

// define main function
int main() {
    int public_key, private_key, message, encrypted_message, decrypted_message;
    generate_keys(&public_key, &private_key);
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);
    printf("Enter message to encrypt: ");
    scanf("%d", &message);
    encrypt(public_key, message, &encrypted_message);
    printf("Encrypted message: %d\n", encrypted_message);
    decrypt(private_key, encrypted_message, &decrypted_message);
    printf("Decrypted message: %d\n", decrypted_message);
    return 0;
}