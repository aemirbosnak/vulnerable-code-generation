//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define HASH_LENGTH 32

// Function for generating a random hash
void generate_hash(char* hash) {
    int i;
    for (i = 0; i < HASH_LENGTH; i++) {
        hash[i] = rand() % 26 + 'A';
    }
    hash[HASH_LENGTH] = '\0';
}

// Function for encrypting a message using the hash
void encrypt_message(char* message, char* hash) {
    int i, j;
    char encrypted_message[strlen(message)];
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[j++] = message[i] ^ hash[i % HASH_LENGTH];
        } else {
            encrypted_message[j++] = message[i];
        }
    }
    encrypted_message[j] = '\0';
    strcpy(message, encrypted_message);
}

// Function for decrypting a message using the hash
void decrypt_message(char* message, char* hash) {
    int i, j;
    char decrypted_message[strlen(message)];
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            decrypted_message[j++] = message[i] ^ hash[i % HASH_LENGTH];
        } else {
            decrypted_message[j++] = message[i];
        }
    }
    decrypted_message[j] = '\0';
    strcpy(message, decrypted_message);
}

int main() {
    char message[1000];
    char hash[HASH_LENGTH + 1];

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Generate random hash
    generate_hash(hash);

    // Encrypt message using hash
    encrypt_message(message, hash);

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt message using hash
    decrypt_message(message, hash);

    // Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}