//Falcon-180B DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 32

// Function to generate a random key
void generate_key(char* key, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
}

// Function to encrypt a message
void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int encrypted_length = message_length + 1; // Add 1 for null terminator
    char* encrypted_message_ptr = encrypted_message;

    for (int i = 0; i < message_length; i++) {
        char message_char = message[i];
        char key_char = key[i % key_length];
        char encrypted_char = (message_char + key_char) % 256;
        encrypted_message_ptr[i] = encrypted_char;
    }

    encrypted_message_ptr[message_length] = '\0';
}

// Function to decrypt a message
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int decrypted_length = encrypted_length - 1; // Subtract 1 for null terminator
    char* decrypted_message_ptr = decrypted_message;

    for (int i = 0; i < encrypted_length; i++) {
        char encrypted_char = encrypted_message[i];
        char key_char = key[i % key_length];
        char decrypted_char = (encrypted_char - key_char + 256) % 256;
        decrypted_message_ptr[i] = decrypted_char;
    }

    decrypted_message_ptr[decrypted_length] = '\0';
}

int main() {
    // Generate a random key
    char key[MAX_KEY_LENGTH];
    generate_key(key, MAX_KEY_LENGTH);

    // Encrypt a message
    char message[] = "Hello, world!";
    char encrypted_message[MAX_KEY_LENGTH + strlen(message)];
    encrypt(message, key, encrypted_message);

    // Decrypt the encrypted message
    char decrypted_message[MAX_KEY_LENGTH + strlen(message)];
    decrypt(encrypted_message, key, decrypted_message);

    // Print the results
    printf("Key: %s\n", key);
    printf("Message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}