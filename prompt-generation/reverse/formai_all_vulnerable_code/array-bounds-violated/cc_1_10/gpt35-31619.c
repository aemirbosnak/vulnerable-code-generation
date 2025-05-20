//FormAI DATASET v1.0 Category: Modern Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to perform XOR encryption
void encrypt(char* message, char* key, char* encrypted_message, int message_length, int key_length) {
    int i;
    for (i = 0; i < message_length; i++) {
        // XOR each character of the message with the corresponding character of the key
        encrypted_message[i] = message[i] ^ key[i % key_length];
    }
    encrypted_message[i] = '\0'; // Add the null character to the end of the encrypted message
}

// Function to perform XOR decryption
void decrypt(char* encrypted_message, char* key, char* decrypted_message, int message_length, int key_length) {
    int i;
    for (i = 0; i < message_length; i++) {
        // XOR each character of the encrypted message with the corresponding character of the key
        decrypted_message[i] = encrypted_message[i] ^ key[i % key_length];
    }
    decrypted_message[i] = '\0'; // Add the null character to the end of the decrypted message
}

int main() {
    char message[1000];
    char key[1000];
    char encrypted_message[1000];
    char decrypted_message[1000];
    int message_length, key_length;

    printf("Enter the message to be encrypted: ");
    fgets(message, sizeof(message), stdin);
    message_length = strlen(message) - 1; // Remove the trailing newline character
    message[message_length] = '\0'; // Add the null character to the end of the message
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key_length = strlen(key) - 1; // Remove the trailing newline character
    key[key_length] = '\0'; // Add the null character to the end of the key

    encrypt(message, key, encrypted_message, message_length, key_length);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message, message_length, key_length);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}