//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// Function to generate a random key of size SIZE
void generate_key(char key[SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

// Function to encrypt the message using the key
void encrypt(char message[SIZE], char key[SIZE], char encrypted_message[SIZE]) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (message[i] - 'a' + key[i % SIZE]) % 26 + 'a';
        } else {
            encrypted_message[i] = message[i];
        }
    }
}

// Function to decrypt the encrypted message using the key
void decrypt(char encrypted_message[SIZE], char key[SIZE], char decrypted_message[SIZE]) {
    int i;
    for (i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = (encrypted_message[i] - 'a' - key[i % SIZE] + 26) % 26 + 'a';
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
}

int main() {
    char message[SIZE];
    char key[SIZE];
    char encrypted_message[SIZE];
    char decrypted_message[SIZE];

    // Get the message from the user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key);

    // Encrypt the message using the key
    encrypt(message, key, encrypted_message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the encrypted message using the key
    decrypt(encrypted_message, key, decrypted_message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}