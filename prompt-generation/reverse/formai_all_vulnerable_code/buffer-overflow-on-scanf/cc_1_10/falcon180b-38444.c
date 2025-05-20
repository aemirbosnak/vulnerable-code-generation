//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Function to generate a random key
void generate_key(char key[MAX_KEY_LENGTH]) {
    srand(time(NULL));
    for (int i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[strlen(key)] = '\0';
}

// Function to encrypt the message using the key
void encrypt(char message[MAX_MESSAGE_LENGTH], char key[MAX_KEY_LENGTH]) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = 'A' + (message[i] - 'A' + key[i % strlen(key)] - 'a') % 26;
            } else {
                message[i] = 'a' + (message[i] - 'a' + key[i % strlen(key)] - 'a') % 26;
            }
        }
    }
}

// Function to decrypt the message using the key
void decrypt(char encrypted_message[MAX_MESSAGE_LENGTH], char key[MAX_KEY_LENGTH]) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            if (isupper(encrypted_message[i])) {
                encrypted_message[i] = 'A' + (encrypted_message[i] - 'A' - key[i % strlen(key)] + 26) % 26;
            } else {
                encrypted_message[i] = 'a' + (encrypted_message[i] - 'a' - key[i % strlen(key)] + 26) % 26;
            }
        }
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];

    // Get the message from the user
    printf("Enter the message: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key);

    // Encrypt the message
    printf("Encrypted message: ");
    encrypt(message, key);
    printf("%s\n", message);

    // Decrypt the message
    printf("Decrypted message: ");
    decrypt(message, key);
    printf("%s\n", message);

    return 0;
}