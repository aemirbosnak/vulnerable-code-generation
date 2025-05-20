//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 1024

// Function to encrypt the message using the key
void encrypt(char* message, char* key) {
    int i, j, n;
    char ciphertext[strlen(message)];
    memset(ciphertext, 0, strlen(message));

    // Apply the key to the message
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                ciphertext[i] = 'A' + ((message[i] - 'A' + key[i % strlen(key)]) % 26);
            } else {
                ciphertext[i] = 'a' + ((message[i] - 'a' + key[i % strlen(key)]) % 26);
            }
        } else {
            ciphertext[i] = message[i];
        }
    }

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);
}

// Function to decrypt the ciphertext using the key
void decrypt(char* ciphertext, char* key) {
    int i, j, n;
    char message[strlen(ciphertext)];
    memset(message, 0, strlen(ciphertext));

    // Apply the key to the ciphertext
    for (i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                message[i] = 'A' + ((ciphertext[i] - 'A' - key[i % strlen(key)]) % 26);
            } else {
                message[i] = 'a' + ((ciphertext[i] - 'a' - key[i % strlen(key)]) % 26);
            }
        } else {
            message[i] = ciphertext[i];
        }
    }

    // Print the message
    printf("Message: %s\n", message);
}

int main() {
    char message[MAX_KEY_SIZE];
    char key[MAX_KEY_SIZE];

    // Get the message and key from the user
    printf("Enter message: ");
    scanf("%s", message);

    printf("Enter key: ");
    scanf("%s", key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the ciphertext
    decrypt(message, key);

    return 0;
}