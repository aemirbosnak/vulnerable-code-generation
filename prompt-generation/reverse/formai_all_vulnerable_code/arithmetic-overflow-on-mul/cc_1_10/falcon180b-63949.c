//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM 1000000
#define MAX_PRIME 1000000
#define MAX_POWER 1000000
#define MAX_EXP 1000000
#define MAX_MOD 1000000

// Function to generate prime numbers
bool is_prime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate the modular exponentiation
int mod_exp(int a, int b, int m) {
    int result = 1;
    while (b > 0) {
        if (b & 1)
            result = (result * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return result;
}

// Function to generate public and private keys
void generate_keys(int *public_key, int *private_key) {
    int p, q, n, phi;
    do {
        p = rand() % MAX_NUM;
        q = rand() % MAX_NUM;
    } while (!is_prime(p) ||!is_prime(q));
    n = p * q;
    phi = (p - 1) * (q - 1);
    *public_key = n;
    *private_key = phi;
}

// Function to encrypt a message
int encrypt(int message, int public_key) {
    return mod_exp(message, public_key, MAX_NUM);
}

// Function to decrypt an encrypted message
int decrypt(int ciphertext, int private_key) {
    return mod_exp(ciphertext, private_key, MAX_NUM);
}

// Main function
int main() {
    int public_key, private_key, message, ciphertext, decrypted_message;
    printf("Generating public and private keys...\n");
    generate_keys(&public_key, &private_key);
    printf("Public key: %d\nPrivate key: %d\n", public_key, private_key);
    printf("Enter message to encrypt: ");
    scanf("%d", &message);
    ciphertext = encrypt(message, public_key);
    printf("Encrypted message: %d\n", ciphertext);
    decrypted_message = decrypt(ciphertext, private_key);
    printf("Decrypted message: %d\n", decrypted_message);
    return 0;
}