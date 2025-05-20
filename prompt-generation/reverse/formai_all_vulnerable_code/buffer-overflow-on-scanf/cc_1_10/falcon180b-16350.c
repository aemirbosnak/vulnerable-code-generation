//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1024

// Function to generate random prime numbers
int is_prime(int n) {
    int i;
    for(i=2; i*i<=n; i++) {
        if(n%i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate public and private keys
void generate_keys(int *public_key, int *private_key) {
    *public_key = rand() % MAX_SIZE + 1;
    *private_key = rand() % MAX_SIZE + 1;
    while(!is_prime(*public_key)) {
        *public_key = rand() % MAX_SIZE + 1;
    }
    while(!is_prime(*private_key)) {
        *private_key = rand() % MAX_SIZE + 1;
    }
}

// Function to encrypt message using public key
int encrypt(int message, int public_key) {
    return (message * public_key) % MAX_SIZE;
}

// Function to decrypt message using private key
int decrypt(int encrypted_message, int private_key) {
    return (encrypted_message * private_key) % MAX_SIZE;
}

int main() {
    int public_key, private_key, message, encrypted_message, decrypted_message;

    // Generate keys
    generate_keys(&public_key, &private_key);

    // Encrypt message using public key
    printf("Enter message to encrypt: ");
    scanf("%d", &message);
    encrypted_message = encrypt(message, public_key);
    printf("Encrypted message: %d\n", encrypted_message);

    // Decrypt message using private key
    decrypted_message = decrypt(encrypted_message, private_key);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}