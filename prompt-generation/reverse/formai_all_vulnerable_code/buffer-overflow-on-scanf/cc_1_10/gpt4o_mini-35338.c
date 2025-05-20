//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_PRIME 65536 // Upper limit for prime generation
#define MAX_KEY_LENGTH 1024 // Maximum length for the message

typedef struct {
    int p;
    int q;
    int n;
    int phi;
    int e;
    int d;
} RSAKeyPair;

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Function to generate a random prime number
int generate_random_prime() {
    int prime;
    do {
        prime = rand() % MAX_PRIME + 2; // Random number between 2 and MAX_PRIME
    } while (!is_prime(prime));
    return prime;
}

// Function to compute GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find the modular multiplicative inverse using Extended Euclidean Algorithm
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m; // Quotient
        t = m; // Store m
        m = a % m; // Update m
        a = t; // Update a
        t = x0; // Store x0

        x0 = x1 - q * x0; // Update x0
        x1 = t; // Update x1
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// RSA Key Pair Generation
RSAKeyPair generate_keypair() {
    RSAKeyPair keyPair;
    keyPair.p = generate_random_prime();
    keyPair.q = generate_random_prime();
    keyPair.n = keyPair.p * keyPair.q;
    keyPair.phi = (keyPair.p - 1) * (keyPair.q - 1);

    // Choosing e
    keyPair.e = 65537; // Commonly used prime number
    while (gcd(keyPair.e, keyPair.phi) != 1) {
        keyPair.e += 2; // Increment by 2 to find a valid e
    }

    // Calculate d
    keyPair.d = mod_inverse(keyPair.e, keyPair.phi);

    return keyPair;
}

// Function to encrypt message
int encrypt(int message, int e, int n) {
    int encrypted = 1;
    for (int i = 0; i < e; i++) {
        encrypted = (encrypted * message) % n;
    }
    return encrypted;
}

// Function to decrypt message
int decrypt(int encrypted, int d, int n) {
    int decrypted = 1;
    for (int i = 0; i < d; i++) {
        decrypted = (decrypted * encrypted) % n;
    }
    return decrypted;
}

// Function to display the key pair
void display_keypair(RSAKeyPair keyPair) {
    printf("Public Key: (e: %d, n: %d)\n", keyPair.e, keyPair.n);
    printf("Private Key: (d: %d)\n", keyPair.d);
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator

    RSAKeyPair keyPair = generate_keypair();
    display_keypair(keyPair);

    // Example message
    int message;
    printf("Enter a message (0 - %d) to encrypt: ", keyPair.n - 1);
    scanf("%d", &message);
    
    if (message < 0 || message >= keyPair.n) {
        printf("Message must be in the range 0 to %d\n", keyPair.n - 1);
        return 1;
    }

    int encrypted_msg = encrypt(message, keyPair.e, keyPair.n);
    int decrypted_msg = decrypt(encrypted_msg, keyPair.d, keyPair.n);

    printf("Encrypted Message: %d\n", encrypted_msg);
    printf("Decrypted Message: %d\n", decrypted_msg);

    return 0;
}