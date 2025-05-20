//Falcon-180B DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 10
#define MAX_MESSAGE_LENGTH 100

// Function to encrypt the message using the key
void encrypt(char message[], char key[]) {
    int i, j, n = strlen(message);
    for (i = 0; i < n; i++) {
        if (isupper(message[i])) {
            message[i] = message[i] + (key[i % strlen(key)] - 'A');
        } else if (islower(message[i])) {
            message[i] = message[i] + (key[i % strlen(key)] - 'a');
        }
    }
}

// Function to decrypt the message using the key
void decrypt(char message[], char key[]) {
    int i, j, n = strlen(message);
    for (i = 0; i < n; i++) {
        if (isupper(message[i])) {
            message[i] = message[i] - (key[i % strlen(key)] - 'A');
        } else if (islower(message[i])) {
            message[i] = message[i] - (key[i % strlen(key)] - 'a');
        }
    }
}

// Function to generate a random key
void generateKey(char key[]) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'A';
    }
}

// Function to get a message from the user
void getMessage(char message[]) {
    printf("Enter a message to encrypt/decrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH], key[MAX_KEY_LENGTH];
    int choice, i;

    // Get the key length from the user
    printf("Enter the length of the key (1-10): ");
    scanf("%d", &choice);

    // Generate a random key
    generateKey(key);

    // Get the message from the user
    getMessage(message);

    // Encrypt the message using the key
    encrypt(message, key);

    // Decrypt the message using the key
    decrypt(message, key);

    // Print the encrypted and decrypted messages
    printf("\nEncrypted message: %s\n", message);
    printf("Decrypted message: %s\n", message);

    return 0;
}