//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to compute the gcd of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to compute (base^exp) % mod using modular exponentiation
unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) // If exp is odd, multiply the base with result
            result = (result * base) % mod;
        base = (base * base) % mod; // Square the base
        exp /= 2; // Divide exp by 2
    }
    return result;
}

// Function to find a prime number greater than a number
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0) return 0;
    return 1;
}

// Function to generate random prime numbers
int generate_random_prime() {
    int num;
    do {
        num = rand() % 100 + 2; // Random number between 2 and 101
    } while (!is_prime(num));
    return num;
}

// Function to generate public and private keys
void generate_keys(int *public_key, int *private_key, int *n) {
    srand(time(NULL));

    int p = generate_random_prime();
    int q = generate_random_prime();

    *n = p * q;
    int phi_n = (p - 1) * (q - 1);

    // Choose e, a prime number
    *public_key = 3; // We can use 3 as a small prime number
    while (gcd(*public_key, phi_n) != 1) {
        (*public_key) += 2; // Increment to find a valid e
    }

    // Calculate d, the modular multiplicative inverse of e mod phi_n
    for (int k = 1; k < phi_n; k++) {
        if ((k * *public_key) % phi_n == 1) {
            *private_key = k;
            break;
        }
    }
}

// Function to encrypt a plaintext message
unsigned long long encrypt(int public_key, int n, int plaintext) {
    return mod_exp(plaintext, public_key, n);
}

// Function to decrypt a ciphertext message
unsigned long long decrypt(int private_key, int n, unsigned long long ciphertext) {
    return mod_exp(ciphertext, private_key, n);
}

int main() {
    int public_key, private_key, n;

    // Generate keys
    generate_keys(&public_key, &private_key, &n);
    
    printf("Public Key (e): %d\n", public_key);
    printf("Private Key (d): %d\n", private_key);
    printf("Modulus (n): %d\n", n);

    int plaintext;
    printf("Enter a number to encrypt (0 - %d): ", n-1);
    scanf("%d", &plaintext);

    unsigned long long encrypted_message = encrypt(public_key, n, plaintext);
    printf("Encrypted message: %llu\n", encrypted_message);

    unsigned long long decrypted_message = decrypt(private_key, n, encrypted_message);
    printf("Decrypted message: %llu\n", decrypted_message);

    return 0;
}