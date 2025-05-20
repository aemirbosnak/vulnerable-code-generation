//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to compute GCD
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to find modular multiplicative inverse
int mod_inverse(int e, int phi) {
    for (int x = 1; x < phi; x++) {
        if ((e * x) % phi == 1) {
            return x;
        }
    }
    return -1; // Inverse doesn't exist
}

// Function to generate random prime numbers (basic function for demo purpose)
int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int generate_prime() {
    int prime;
    do {
        prime = rand() % 100 + 2; // Random number between 2 and 100
    } while (!is_prime(prime));
    return prime;
}

// Function to generate public and private key pair
void generate_keypair(int *public_key, int *private_key, int *n) {
    int p = generate_prime();
    int q = generate_prime();
    *n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = 2; // Starting point for e
    while (e < phi) {
        if (gcd(e, phi) == 1) {
            break;
        }
        e++;
    }

    *public_key = e;
    *private_key = mod_inverse(e, phi);
}

// Function to encrypt a message
int encrypt(int message, int public_key, int n) {
    int encrypted = 1;
    for (int i = 0; i < public_key; i++) {
        encrypted = (encrypted * message) % n;
    }
    return encrypted;
}

// Function to decrypt a message
int decrypt(int encrypted_message, int private_key, int n) {
    int decrypted = 1;
    for (int i = 0; i < private_key; i++) {
        decrypted = (decrypted * encrypted_message) % n;
    }
    return decrypted;
}

int main() {
    srand(time(NULL)); // Seed for randomness

    int public_key, private_key, n;

    generate_keypair(&public_key, &private_key, &n);
    
    printf("Public Key: %d\n", public_key);
    printf("Private Key: %d\n", private_key);
    printf("N: %d\n", n);

    int message;
    printf("Enter a message (integer) to encrypt: ");
    scanf("%d", &message);
    
    int encrypted_message = encrypt(message, public_key, n);
    printf("Encrypted Message: %d\n", encrypted_message);
    
    int decrypted_message = decrypt(encrypted_message, private_key, n);
    printf("Decrypted Message: %d\n", decrypted_message);
    
    return 0;
}