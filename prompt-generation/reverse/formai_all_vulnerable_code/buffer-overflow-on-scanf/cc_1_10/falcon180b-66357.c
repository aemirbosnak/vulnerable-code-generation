//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_BYTES 1000
#define PUBLIC_KEY_BYTES 64
#define PRIVATE_KEY_BYTES 32

// Function to generate a random number
int rand_num() {
    return rand() % 256;
}

// Function to generate a random public key
void generate_public_key(unsigned char* public_key) {
    for (int i = 0; i < PUBLIC_KEY_BYTES; i++) {
        public_key[i] = rand_num();
    }
}

// Function to generate a random private key
void generate_private_key(unsigned char* private_key) {
    for (int i = 0; i < PRIVATE_KEY_BYTES; i++) {
        private_key[i] = rand_num();
    }
}

// Function to encrypt a message using the public key
void encrypt_message(unsigned char* message, unsigned char* public_key, unsigned char* encrypted_message) {
    for (int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = message[i] ^ public_key[i % PUBLIC_KEY_BYTES];
    }
}

// Function to decrypt a message using the private key
void decrypt_message(unsigned char* encrypted_message, unsigned char* private_key, char* decrypted_message) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = encrypted_message[i] ^ private_key[i % PRIVATE_KEY_BYTES];
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
}

int main() {
    srand(time(NULL));
    unsigned char public_key[PUBLIC_KEY_BYTES];
    unsigned char private_key[PRIVATE_KEY_BYTES];
    unsigned char message[MAX_NUM_BYTES];
    unsigned char encrypted_message[MAX_NUM_BYTES];
    char decrypted_message[MAX_NUM_BYTES];

    // Generate public and private keys
    generate_public_key(public_key);
    generate_private_key(private_key);

    // Get message from user
    printf("Enter message: ");
    scanf("%s", message);

    // Encrypt message using public key
    encrypt_message(message, public_key, encrypted_message);

    // Decrypt message using private key
    decrypt_message(encrypted_message, private_key, decrypted_message);

    // Print decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}