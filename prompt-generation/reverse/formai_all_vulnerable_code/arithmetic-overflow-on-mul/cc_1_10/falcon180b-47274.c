//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10000000

// Function to generate random prime number
int is_prime(int n) {
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    int i;
    for (i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// Function to generate public and private keys
void generate_keys(int *public_key, int *private_key) {
    int i;
    for (i = 0; i < 2; i++) {
        do {
            (*public_key) = rand() % MAX_NUM;
        } while (!is_prime((*public_key)));

        do {
            (*private_key) = rand() % MAX_NUM;
        } while (!is_prime((*private_key)));
    }
}

// Function to encrypt message using public key
int encrypt(int message, int public_key) {
    return (message * public_key) % MAX_NUM;
}

// Function to decrypt message using private key
int decrypt(int encrypted_message, int private_key) {
    return (encrypted_message * private_key) % MAX_NUM;
}

int main() {
    int public_key, private_key, message, encrypted_message, decrypted_message;

    // Generate public and private keys
    generate_keys(&public_key, &private_key);

    // Get message from user
    printf("Enter message to encrypt: ");
    scanf("%d", &message);

    // Encrypt message using public key
    encrypted_message = encrypt(message, public_key);

    // Decrypt message using private key
    decrypted_message = decrypt(encrypted_message, private_key);

    // Print original and decrypted messages
    printf("Original message: %d\n", message);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}