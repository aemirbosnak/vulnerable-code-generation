//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Function to generate a random key
void generate_key(char key[MAX_KEY_LENGTH]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

// Function to encrypt the message using the key
void encrypt(char message[MAX_MESSAGE_LENGTH], char key[MAX_KEY_LENGTH]) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] + key[i % strlen(key)];
        }
    }
}

// Function to decrypt the message using the key
void decrypt(char message[MAX_MESSAGE_LENGTH], char key[MAX_KEY_LENGTH]) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] - key[i % strlen(key)];
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the message from the user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key);

    // Encrypt the message using the key
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Get the encrypted message from the user
    printf("Enter the encrypted message: ");
    scanf("%s", message);

    // Decrypt the message using the key
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}