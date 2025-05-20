//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 1000

// Function to encrypt the message using the given key
void encrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    if (key_length > MAX_KEY_LENGTH) {
        printf("Error: Key is too long.\n");
        return;
    }

    for (int i = 0; i < message_length; i++) {
        char c = tolower(message[i]);
        int k = tolower(key[i % key_length]) - 'a';

        if (isalpha(c)) {
            c = (c - 'a' + k) % 26 + 'a';
        }

        message[i] = c;
    }
}

// Function to decrypt the message using the given key
void decrypt(char* message, char* key) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    if (key_length > MAX_KEY_LENGTH) {
        printf("Error: Key is too long.\n");
        return;
    }

    for (int i = 0; i < message_length; i++) {
        char c = tolower(message[i]);
        int k = tolower(key[i % key_length]) - 'a';

        if (isalpha(c)) {
            c = (c - 'a' - k + 26) % 26 + 'a';
        }

        message[i] = c;
    }
}

// Function to generate a random key of the given length
void generate_key(char* key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = 'a' + rand() % 26;
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key, rand() % MAX_KEY_LENGTH + 1);

    // Encrypt the message using the key
    encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the key
    decrypt(message, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}