//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[KEY_LENGTH] = '\0';
}

// Function to encrypt a message
void encrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            char c = message[i];
            if (isupper(c)) {
                c = 'A' + (c - 'A' + tolower(key[j]) - 'a') % 26;
            } else {
                c = 'a' + (c - 'a' + tolower(key[j]) - 'a') % 26;
            }
            message[i] = c;
            j = (j + 1) % KEY_LENGTH;
        }
    }
}

// Function to decrypt a message
void decrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            char c = message[i];
            if (isupper(c)) {
                c = 'A' + (c - 'A' + toupper(key[j]) - 'A') % 26;
            } else {
                c = 'a' + (c - 'a' + toupper(key[j]) - 'A') % 26;
            }
            message[i] = c;
            j = (j + 1) % KEY_LENGTH;
        }
    }
}

int main() {
    char message[1000], key[KEY_LENGTH + 1];
    int i, n;

    // Generate a random key
    generate_key(key);

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    n = strlen(message);

    // Remove newline character
    message[n - 1] = '\0';

    // Encrypt message
    encrypt(message, key);

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    decrypt(message, key);

    // Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}