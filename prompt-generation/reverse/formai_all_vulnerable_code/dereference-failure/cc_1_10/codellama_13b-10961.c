//Code Llama-13B DATASET v1.0 Category: Cryptography Implementation ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to encrypt a message using the Vigenere cipher
char* encrypt_message(char* message, char* key) {
    char* encrypted_message = malloc(strlen(message) * sizeof(char));
    int key_index = 0;
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (((message[i] - 'A') + (key[key_index] - 'A')) % 26) + 'A';
            key_index = (key_index + 1) % strlen(key);
        } else {
            encrypted_message[i] = message[i];
        }
    }
    return encrypted_message;
}

// Function to decrypt a message using the Vigenere cipher
char* decrypt_message(char* encrypted_message, char* key) {
    char* message = malloc(strlen(encrypted_message) * sizeof(char));
    int key_index = 0;
    for (int i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            message[i] = (((encrypted_message[i] - 'A') - (key[key_index] - 'A')) % 26) + 'A';
            key_index = (key_index + 1) % strlen(key);
        } else {
            message[i] = encrypted_message[i];
        }
    }
    return message;
}

// Main function
int main() {
    // Get message and key from user
    char message[100];
    char key[100];
    printf("Enter message: ");
    fgets(message, 100, stdin);
    printf("Enter key: ");
    fgets(key, 100, stdin);

    // Encrypt message using key
    char* encrypted_message = encrypt_message(message, key);

    // Decrypt message using key
    char* decrypted_message = decrypt_message(encrypted_message, key);

    // Print encrypted and decrypted messages
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}