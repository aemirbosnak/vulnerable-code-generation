//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Cryptography Implementation in C */

// Function to encrypt the message
void encrypt(char message[], int key) {
    int length = strlen(message);
    int i;
    for (i = 0; i < length; i++) {
        message[i] = message[i] + key;
    }
}

// Function to decrypt the message
void decrypt(char message[], int key) {
    int length = strlen(message);
    int i;
    for (i = 0; i < length; i++) {
        message[i] = message[i] - key;
    }
}

// Main Function
int main() {
    char message[100];
    int key;

    // Get the message to be encrypted/decrypted from the user
    printf("Enter the message: ");
    fgets(message, 100, stdin);

    // Get the key from the user
    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the message using the key
    encrypt(message, key);

    // Display the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the same key
    decrypt(message, key);

    // Display the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}