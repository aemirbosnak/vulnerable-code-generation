//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_KEY_SIZE 10
#define MAX_MSG_SIZE 100

// Function to encrypt the message using Vigenere cipher
void encrypt(char *message, char *key) {
    int i, j, n = strlen(message);
    int k = strlen(key);

    // Repeat the key to match the length of message
    while (k < n) {
        strcat(key, key);
        k++;
    }

    int key_index = 0;
    for (i = 0; i < n; i++) {
        if (isalpha(message[i])) {
            message[i] = (char) ((message[i] - 'A' + key[key_index] - 'A') % 26 + 'A');
            key_index++;
            if (key_index >= k) {
                key_index = 0;
            }
        }
    }
}

// Function to decrypt the message using Vigenere cipher
void decrypt(char *message, char *key) {
    int i, j, n = strlen(message);
    int k = strlen(key);

    // Repeat the key to match the length of message
    while (k < n) {
        strcat(key, key);
        k++;
    }

    int key_index = 0;
    for (i = 0; i < n; i++) {
        if (isalpha(message[i])) {
            message[i] = (char) ((message[i] - 'A' + 'Z' - key[key_index]) % 26 + 'A');
            key_index++;
            if (key_index >= k) {
                key_index = 0;
            }
        }
    }
}

int main() {
    char message[MAX_MSG_SIZE];
    char key[MAX_KEY_SIZE];

    // Get the message and key from user
    printf("Enter the message to encrypt/decrypt: ");
    scanf("%s", message);
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}