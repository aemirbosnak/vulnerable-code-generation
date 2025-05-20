//Falcon-180B DATASET v1.0 Category: Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024

// Function to encrypt the message using the key
void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[MAX_MESSAGE_LENGTH];

    // Pad the key with zeros to make it the same length as the message
    while (key_length < message_length) {
        strcat(key, "0");
        key_length++;
    }

    // XOR each character of the message with the corresponding character of the key
    for (int i = 0; i < message_length; i++) {
        char message_char = message[i];
        char key_char = key[i % key_length];
        char encrypted_char = message_char ^ key_char;
        strncat(encrypted_message, &encrypted_char, 1);
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the encrypted message using the key
void decrypt(char* encrypted_message, char* key) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    char decrypted_message[MAX_MESSAGE_LENGTH];

    // Pad the key with zeros to make it the same length as the encrypted message
    while (key_length < encrypted_message_length) {
        strcat(key, "0");
        key_length++;
    }

    // XOR each character of the encrypted message with the corresponding character of the key
    for (int i = 0; i < encrypted_message_length; i++) {
        char encrypted_char = encrypted_message[i];
        char key_char = key[i % key_length];
        char decrypted_char = encrypted_char ^ key_char;
        strncat(decrypted_message, &decrypted_char, 1);
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the message from the user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the encrypted message
    decrypt(message, key);

    return 0;
}