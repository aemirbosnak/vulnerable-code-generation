//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int e; // public key
    int n; // modulus
} PublicKey;

typedef struct {
    int d; // private key
    int n; // modulus
} PrivateKey;

// Function to compute gcd
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to compute modular inverse
int modInverse(int e, int phi) {
    for (int x = 1; x < phi; x++) {
        if ((e * x) % phi == 1) 
            return x;
    }
    return -1; // returns -1 if no modular inverse exists
}

// Function to generate keys
void generateKeys(int p, int q, PublicKey *pubKey, PrivateKey *privKey) {
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    
    // Choose e
    int e = 3;
    while (gcd(e, phi) != 1) {
        e += 2; // Increase to find coprime
    }
    
    // Calculate d
    int d = modInverse(e, phi);
    
    // Assign keys
    pubKey->e = e;
    pubKey->n = n;
    privKey->d = d;
    privKey->n = n;
}

// Function to encrypt a message
int encrypt(int plaintext, PublicKey pubKey) {
    int ciphertext = 1;
    for (int i = 0; i < pubKey.e; i++) {
        ciphertext = (ciphertext * plaintext) % pubKey.n;
    }
    return ciphertext;
}

// Function to decrypt a message
int decrypt(int ciphertext, PrivateKey privKey) {
    int plaintext = 1;
    for (int i = 0; i < privKey.d; i++) {
        plaintext = (plaintext * ciphertext) % privKey.n;
    }
    return plaintext;
}

int main() {
    PublicKey pubKey;
    PrivateKey privKey;
    int p, q, plaintext, encrypted, decrypted;

    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);

    // Generate public and private keys
    generateKeys(p, q, &pubKey, &privKey);

    printf("Public Key: (e = %d, n = %d)\n", pubKey.e, pubKey.n);
    printf("Private Key: (d = %d, n = %d)\n", privKey.d, privKey.n);

    printf("Enter a message to encrypt (as an integer): ");
    scanf("%d", &plaintext);

    encrypted = encrypt(plaintext, pubKey);
    printf("Encrypted message: %d\n", encrypted);

    decrypted = decrypt(encrypted, privKey);
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}