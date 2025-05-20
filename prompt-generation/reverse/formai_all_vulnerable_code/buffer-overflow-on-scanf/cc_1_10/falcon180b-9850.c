//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to generate prime numbers
int is_prime(int n) {
    int i;
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate public and private keys
void generate_keys(int* public_key, int* private_key) {
    *public_key = rand() % MAX_SIZE + 1;
    *private_key = rand() % MAX_SIZE + 1;
    while (!is_prime(*public_key)) {
        *public_key = rand() % MAX_SIZE + 1;
    }
    while (!is_prime(*private_key)) {
        *private_key = rand() % MAX_SIZE + 1;
    }
}

// Function to encrypt message using public key
void encrypt(int message, int public_key, int* encrypted_message) {
    *encrypted_message = (message * public_key) % MAX_SIZE;
}

// Function to decrypt message using private key
void decrypt(int encrypted_message, int private_key, int* decrypted_message) {
    *decrypted_message = (encrypted_message * private_key) % MAX_SIZE;
}

int main() {
    int public_key, private_key, message, encrypted_message, decrypted_message;
    srand(time(NULL));
    generate_keys(&public_key, &private_key);
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);
    printf("Enter message to encrypt: ");
    scanf("%d", &message);
    encrypt(message, public_key, &encrypted_message);
    printf("Encrypted message: %d\n", encrypted_message);
    decrypt(encrypted_message, private_key, &decrypted_message);
    printf("Decrypted message: %d\n", decrypted_message);
    return 0;
}