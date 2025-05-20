//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRIME 100
#define MESSAGE_LENGTH 255

// Function prototypes
int is_prime(int num);
void generate_keys(int *public_key, int *private_key);
int encrypt(int message, int public_key);
int decrypt(int cipher, int private_key);

int main() {
    int public_key, private_key;
    int message, cipher;

    // Generate public and private keys
    generate_keys(&public_key, &private_key);
    
    printf("Public Key: %d\n", public_key);
    printf("Private Key: %d\n", private_key);
    
    // Input the message to be encrypted
    printf("Enter an integer message to encrypt (0 to %d): ", MAX_PRIME);
    scanf("%d", &message);
    
    if (message < 0 || message > MAX_PRIME) {
        printf("Message out of bounds!\n");
        return 1;
    }

    // Encrypt the message
    cipher = encrypt(message, public_key);
    printf("Encrypted Message (Cipher): %d\n", cipher);
    
    // Decrypt the message
    message = decrypt(cipher, private_key);
    printf("Decrypted Message: %d\n", message);
    
    return 0;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Generate public and private keys for a simple public-key algorithm
void generate_keys(int *public_key, int *private_key) {
    srand(time(0));
    int p, q, n, phi_n;

    // Choose two distinct prime numbers
    do {
        p = rand() % MAX_PRIME;
    } while (!is_prime(p));
  
    do {
        q = rand() % MAX_PRIME;
    } while (!is_prime(q) || q == p);

    n = p * q; // Calculate n
    phi_n = (p - 1) * (q - 1); // Calculate φ(n)

    // Public key is n, we use a fixed e for simplicity
    *public_key = n + 1; // e = n + 1 (for our simple case)
    *private_key = phi_n + 1; // d = φ(n) + 1
}

// Encrypt the message using public key
int encrypt(int message, int public_key) {
    return (message + public_key); // Shift message based on public_key
}

// Decrypt the message using private key
int decrypt(int cipher, int private_key) {
    return (cipher - private_key); // Reverse shift based on private_key
}