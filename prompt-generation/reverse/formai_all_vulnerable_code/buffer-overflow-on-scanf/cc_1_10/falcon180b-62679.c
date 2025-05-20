//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1024
#define ALPHABET_LENGTH 26

// Function to generate a random key
void generate_key(char* key) {
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % ALPHABET_LENGTH + 'a';
    }
    key[MAX_KEY_LENGTH] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key) {
    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] ^ key[i % MAX_KEY_LENGTH];
    }
}

// Function to decrypt the message using the key
void decrypt(char* message, char* key) {
    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] ^ key[i % MAX_KEY_LENGTH];
    }
}

// Function to display the encrypted message
void display_encrypted(char* message) {
    printf("Encrypted message: %s\n", message);
}

// Function to display the decrypted message
void display_decrypted(char* message) {
    printf("Decrypted message: %s\n", message);
}

int main() {
    srand(time(NULL));

    // Get the message from the user
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Generate a random key
    char key[MAX_KEY_LENGTH];
    generate_key(key);

    // Encrypt the message
    encrypt(message, key);

    // Display the encrypted message
    display_encrypted(message);

    // Decrypt the message
    decrypt(message, key);

    // Display the decrypted message
    display_decrypted(message);

    return 0;
}