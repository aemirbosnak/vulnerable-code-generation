//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_PRIME 5000

// Function prototypes
int is_prime(int num);
void generate_keys(int *public_key, int *private_key);
int mod_inverse(int a, int m);
int encrypt(int message, int public_key[]);
int decrypt(int cipher, int private_key[]);

// Entry point of the program
int main() {
    int public_key[2];     // public_key = {e, n}
    int private_key[2];    // private_key = {d, n}
    int message;
    
    // Generate public and private keys
    generate_keys(public_key, private_key);
    
    printf("Public Key: [e: %d, n: %d]\n", public_key[0], public_key[1]);
    printf("Private Key: [d: %d, n: %d]\n", private_key[0], private_key[1]);
    
    // Get a message from user
    printf("Enter a message to encrypt (numeric values only): ");
    scanf("%d", &message);
    
    // Encrypt the message
    int cipher = encrypt(message, public_key);
    printf("Encrypted Message: %d\n", cipher);
    
    // Decrypt the message
    int decrypted_message = decrypt(cipher, private_key);
    printf("Decrypted Message: %d\n", decrypted_message);
    
    return 0;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0; // Not prime
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0; // Not prime
    }
    return 1; // Prime
}

// Function to generate public and private keys
void generate_keys(int *public_key, int *private_key) {
    int p = 0, q = 0;

    // Generate two distinct prime numbers p and q
    srand(time(0));
    while (!is_prime(p)) {
        p = rand() % MAX_PRIME;
    }
    while (!is_prime(q) || q == p) {
        q = rand() % MAX_PRIME;
    }

    // Calculate n = p * q
    int n = p * q;

    // Calculate Euler's Totient (φ(n)) = (p - 1) * (q - 1)
    int phi = (p - 1) * (q - 1);

    // Choose an integer e such that 1 < e < φ(n) and gcd(e, φ(n)) = 1
    int e = 2; // Start with the smallest prime
    while (e < phi) {
        if (phi % e != 0) break; // e should be coprime to phi
        e++;
    }

    public_key[0] = e;
    public_key[1] = n;

    // Calculate d such that (d * e) mod φ(n) = 1
    private_key[0] = mod_inverse(e, phi);
    private_key[1] = n;
}

// Function to compute modular inverse
int mod_inverse(int a, int m) {
    a = a % m; 
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return 1; // This should never happen in a valid RSA key generation
}

// Function to encrypt the message
int encrypt(int message, int public_key[]) {
    int e = public_key[0];
    int n = public_key[1];
    int result = 1;

    for (int i = 0; i < e; i++) {
        result = (result * message) % n;
    }
    
    return result;
}

// Function to decrypt the cipher
int decrypt(int cipher, int private_key[]) {
    int d = private_key[0];
    int n = private_key[1];
    int result = 1;

    for (int i = 0; i < d; i++) {
        result = (result * cipher) % n;
    }
    
    return result;
}