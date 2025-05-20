//Falcon-180B DATASET v1.0 Category: Encryption ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt message
void encrypt(char *message) {
    int length = strlen(message);
    int key = 3; // Key for encryption

    // Loop through each character in the message
    for (int i = 0; i < length; i++) {
        // Encrypt uppercase characters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] + key;
            if (message[i] > 'Z') {
                message[i] = message[i] - 26;
            }
        }
        // Encrypt lowercase characters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] + key;
            if (message[i] > 'z') {
                message[i] = message[i] - 26;
            }
        }
    }
}

// Function to decrypt message
void decrypt(char *message) {
    int length = strlen(message);
    int key = 3; // Key for decryption

    // Loop through each character in the message
    for (int i = 0; i < length; i++) {
        // Decrypt uppercase characters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = message[i] - key;
            if (message[i] < 'A') {
                message[i] = message[i] + 26;
            }
        }
        // Decrypt lowercase characters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = message[i] - key;
            if (message[i] < 'a') {
                message[i] = message[i] + 26;
            }
        }
    }
}

int main() {
    char message[100];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Encrypt message
    encrypt(message);
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    decrypt(message);
    printf("Decrypted message: %s\n", message);

    return 0;
}