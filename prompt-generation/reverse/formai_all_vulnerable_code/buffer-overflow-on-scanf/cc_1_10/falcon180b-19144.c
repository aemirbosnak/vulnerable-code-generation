//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1024

// Function to generate a random key
void generate_key(char* key) {
    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_SIZE - 1] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++) {
        char c = toupper(message[i]);
        if (isalpha(c)) {
            int key_index = (c - 'A') % key_length;
            c = (c - 'A' + key[key_index]) % 26 + 'A';
            message[i] = c;
        }
    }
}

// Function to decrypt the message using the key
void decrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i = 0; i < message_length; i++) {
        char c = toupper(message[i]);
        if (isalpha(c)) {
            int key_index = (c - 'A') % key_length;
            c = (c - 'A' - key[key_index] + 26) % 26 + 'A';
            message[i] = c;
        }
    }
}

// Function to print the message
void print_message(char* message) {
    printf("Message: %s\n", message);
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key);

    // Encrypt the message using the key
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: ");
    print_message(message);

    // Decrypt the message using the key
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: ");
    print_message(message);

    return 0;
}