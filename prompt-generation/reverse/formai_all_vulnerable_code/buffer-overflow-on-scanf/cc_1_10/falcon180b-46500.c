//Falcon-180B DATASET v1.0 Category: Encryption ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Function to generate a random key
void generate_key(char* key, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for(int i=0; i<length; i++) {
        key[i] = charset[rand()%strlen(charset)];
    }
}

// Function to encrypt the message
void encrypt_message(char* message, int length, char* key) {
    int key_index = 0;
    for(int i=0; i<length; i++) {
        message[i] = message[i] ^ key[key_index];
        key_index++;
        if(key_index == strlen(key)) {
            key_index = 0;
        }
    }
}

// Function to decrypt the message
void decrypt_message(char* message, int length, char* key) {
    int key_index = 0;
    for(int i=0; i<length; i++) {
        message[i] = message[i] ^ key[key_index];
        key_index++;
        if(key_index == strlen(key)) {
            key_index = 0;
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key, strlen(message));

    // Encrypt the message
    encrypt_message(message, strlen(message), key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt_message(message, strlen(message), key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}