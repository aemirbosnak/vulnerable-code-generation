//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PRIME 1000

// Function declarations
int is_prime(int num);
void generate_keys(int *public_key, int *private_key);
int gcd(int a, int b);
int mod_inverse(int a, int m);
int encrypt(int msg, int e, int n);
int decrypt(int enc_msg, int d, int n);

int main() {
    printf("-------------------------------------------------\n");
    printf("         RSA Public-Key Cryptography            \n");
    printf("-------------------------------------------------\n\n");

    int public_key[2];  // {n, e}
    int private_key[2]; // {n, d}

    generate_keys(public_key, private_key);

    printf("Public Key (n, e): (%d, %d)\n", public_key[0], public_key[1]);
    printf("Private Key (n, d): (%d, %d)\n", private_key[0], private_key[1]);

    int msg;
    printf("\nEnter a message (integer): ");
    scanf("%d", &msg);

    int enc_msg = encrypt(msg, public_key[1], public_key[0]);
    printf("Encrypted message: %d\n", enc_msg);

    int dec_msg = decrypt(enc_msg, private_key[1], private_key[0]);
    printf("Decrypted message: %d\n", dec_msg);

    printf("-------------------------------------------------\n");
    return 0;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Function to generate public and private keys
void generate_keys(int *public_key, int *private_key) {
    int p = 0, q = 0;

    // Find two distinct prime numbers p and q
    for (int i = 2; i < MAX_PRIME; i++) {
        if (is_prime(i)) {
            if (p == 0) p = i;
            else if (q == 0 && i != p) q = i;
            if (p != 0 && q != 0) break;
        }
    }

    int n = p * q;        // n = p * q
    int phi = (p - 1) * (q - 1); // φ(n)

    // Public exponent e
    int e;
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) break;
    }

    // Private exponent d
    int d = mod_inverse(e, phi);

    // Assign keys
    public_key[0] = n;
    public_key[1] = e;
    private_key[0] = n;
    private_key[1] = d;
}

// Function to calculate gcd
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to calculate modular inverse
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return 0; // Should never occur with valid inputs
}

// Function to encrypt the message
int encrypt(int msg, int e, int n) {
    int enc_msg = 1;
    for (int i = 0; i < e; i++) {
        enc_msg = (enc_msg * msg) % n;
    }
    return enc_msg;
}

// Function to decrypt the message
int decrypt(int enc_msg, int d, int n) {
    int dec_msg = 1;
    for (int i = 0; i < d; i++) {
        dec_msg = (dec_msg * enc_msg) % n;
    }
    return dec_msg;
}