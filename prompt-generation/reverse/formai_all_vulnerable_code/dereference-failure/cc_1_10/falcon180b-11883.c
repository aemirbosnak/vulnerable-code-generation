//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_MESSAGE_SIZE 1024

// Function prototypes
void generate_key(char *key, int key_size);
void encrypt(char *message, char *key, char *encrypted_message);
void decrypt(char *encrypted_message, char *key, char *decrypted_message);

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    char encrypted_message[MAX_MESSAGE_SIZE];
    char decrypted_message[MAX_MESSAGE_SIZE];

    // Get message from user
    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    // Generate key
    generate_key(key, strlen(message));

    // Encrypt message
    encrypt(message, key, encrypted_message);

    // Decrypt message
    decrypt(encrypted_message, key, decrypted_message);

    // Print results
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}

// Generates a random key of specified length
void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = (char)rand() % 26 + 'A';
    }
    key[key_size] = '\0';
}

// Encrypts message using key
void encrypt(char *message, char *key, char *encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int encrypted_message_length = message_length + 1;

    encrypted_message[encrypted_message_length - 1] = '\0';

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            char c = tolower(message[i]);
            int k = tolower(key[i % key_length]) - 'a';

            if (isupper(message[i])) {
                c = toupper(c);
            }

            encrypted_message[i] = (char)((c - k - 1) % 26 + 'A');
        } else {
            encrypted_message[i] = message[i];
        }
    }
}

// Decrypts message using key
void decrypt(char *encrypted_message, char *key, char *decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int decrypted_message_length = encrypted_message_length;

    decrypted_message[decrypted_message_length - 1] = '\0';

    for (int i = 0; i < encrypted_message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            char c = toupper(encrypted_message[i]);
            int k = tolower(key[i % key_length]) - 'a';

            if (isupper(encrypted_message[i])) {
                c = tolower(c);
            }

            decrypted_message[i] = (char)((c - k - 1 + 26) % 26 + 'A');
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
}