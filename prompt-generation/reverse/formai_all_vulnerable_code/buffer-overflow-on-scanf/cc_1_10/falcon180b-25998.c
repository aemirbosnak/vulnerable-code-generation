//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 256
#define MAX_MESSAGE_LENGTH 1000

// Function to encrypt the message using the key
void encrypt(char *message, char *key) {
    int i, j, n;
    char ciphertext[MAX_MESSAGE_LENGTH];

    // Calculate the length of the message
    n = strlen(message);

    // Initialize the ciphertext
    for (i = 0; i < n; i++) {
        ciphertext[i] = message[i];
    }

    // Encrypt the message
    for (i = 0; i < n; i++) {
        if (isalpha(ciphertext[i])) {
            ciphertext[i] = (((ciphertext[i] - 'a') + (key[i % strlen(key)] - 'a')) % 26) + 'a';
        }
        else {
            ciphertext[i] = ciphertext[i];
        }
    }

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);
}

// Function to decrypt the message using the key
void decrypt(char *ciphertext, char *key) {
    int i, j, n;
    char message[MAX_MESSAGE_LENGTH];

    // Calculate the length of the ciphertext
    n = strlen(ciphertext);

    // Initialize the message
    for (i = 0; i < n; i++) {
        message[i] = ciphertext[i];
    }

    // Decrypt the ciphertext
    for (i = 0; i < n; i++) {
        if (isalpha(message[i])) {
            message[i] = (((message[i] - 'a') - (key[i % strlen(key)] - 'a')) % 26) + 'a';
        }
        else {
            message[i] = message[i];
        }
    }

    // Print the message
    printf("Message: %s\n", message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    int i;

    // Get the message from the user
    printf("Enter the message: ");
    scanf("%s", message);

    // Get the key from the user
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the ciphertext
    decrypt(message, key);

    return 0;
}