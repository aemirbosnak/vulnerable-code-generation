//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 32

// Function to generate random number
int rand_int(int max) {
    return rand() % max;
}

// Function to generate random prime number
int rand_prime() {
    int num;
    do {
        num = rand_int(SIZE) + 2;
    } while (!is_prime(num));
    return num;
}

// Function to check if a number is prime
int is_prime(int num) {
    int i;
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate modular exponentiation
int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to generate public and private keys
void generate_keys(int *public_key, int *private_key) {
    int p, q, n, phi;
    do {
        p = rand_prime();
        q = rand_prime();
        n = p * q;
        phi = (p - 1) * (q - 1);
    } while (phi % 2 == 0);
    *public_key = n;
    *private_key = phi;
}

// Function to encrypt message
int encrypt(int public_key, int message) {
    return mod_exp(message, public_key, SIZE);
}

// Function to decrypt message
int decrypt(int private_key, int encrypted_message) {
    return mod_exp(encrypted_message, private_key, SIZE);
}

// Main function
int main() {
    int public_key, private_key, message, encrypted_message, decrypted_message;
    srand(time(NULL));
    generate_keys(&public_key, &private_key);
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);
    printf("Enter message to encrypt: ");
    scanf("%d", &message);
    encrypted_message = encrypt(public_key, message);
    printf("Encrypted message: %d\n", encrypted_message);
    decrypted_message = decrypt(private_key, encrypted_message);
    printf("Decrypted message: %d\n", decrypted_message);
    return 0;
}