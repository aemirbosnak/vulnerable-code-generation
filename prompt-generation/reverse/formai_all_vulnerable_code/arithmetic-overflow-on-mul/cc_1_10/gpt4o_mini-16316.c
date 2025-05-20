//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Post-Apocalyptic Public Key Structure
typedef struct {
    long long int n; // Modulus
    long long int e; // Public exponent
} PublicKey;

typedef struct {
    long long int n; // Modulus
    long long int d; // Private exponent
} PrivateKey;

// Function to generate a random large prime (For simplicity, using smaller primes)
long long int generate_prime() {
    return 61; // Replace with a function that generates large primes
}

// Function to compute gcd
long long int gcd(long long int a, long long int b) {
    while (b != 0) {
        long long int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to compute modular inverse using Extended Euclidean Algorithm
long long int mod_inverse(long long int a, long long int m) {
    long long int m0 = m, t, q;
    long long int x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

// Function to encrypt message
long long int encrypt(long long int plaintext, PublicKey pubkey) {
    long long int ciphertext = 1;
    long long int base = plaintext;

    for (long long int i = 0; i < pubkey.e; i++) {
        ciphertext = (ciphertext * base) % pubkey.n;
    }

    return ciphertext;
}

// Function to decrypt message
long long int decrypt(long long int ciphertext, PrivateKey privkey) {
    long long int plaintext = 1;
    long long int base = ciphertext;

    for (long long int i = 0; i < privkey.d; i++) {
        plaintext = (plaintext * base) % privkey.n;
    }

    return plaintext;
}

// Function to initialize keys
void generate_keys(PublicKey* pubkey, PrivateKey* privkey) {
    long long int p = generate_prime();
    long long int q = generate_prime();
    pubkey->n = p * q;
    long long int phi = (p - 1) * (q - 1);
    
    // Set public exponent as a small number
    pubkey->e = 17; 
    
    // Compute private exponent
    privkey->d = mod_inverse(pubkey->e, phi);
    privkey->n = pubkey->n;
}

// Function to simulate the apocalypse environment
void post_apocalyptic_display() {
    printf("=========================================\n");
    printf("Welcome to the Post-Apocalyptic Encryption Realm\n");
    printf("=========================================\n");
    printf("Survivor, safeguard your data with public-key encryption.\n");
    printf("Trust in the shadows of the fallen world.\n");
    printf("=========================================\n");
}

int main() {
    PublicKey pubkey;
    PrivateKey privkey;
    long long int plaintext;
    long long int ciphertext;

    post_apocalyptic_display();

    // Generate keys
    generate_keys(&pubkey, &privkey);

    printf("Enter a message to encrypt (as a number): ");
    scanf("%lld", &plaintext);

    // Encrypt
    ciphertext = encrypt(plaintext, pubkey);
    printf("Encrypted message: %lld\n", ciphertext);

    // Decrypt
    long long int decrypted_message = decrypt(ciphertext, privkey);
    printf("Decrypted message: %lld\n", decrypted_message);

    printf("=========================================\n");
    printf("You have unlocked the secrets of encryption.\n");
    printf("Stay safe in the remnants of the old world.\n");
    printf("=========================================\n");

    return 0;
}