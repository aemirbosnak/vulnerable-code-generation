//FormAI DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char* message, int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }
}

// Function to decrypt the message
void decrypt(char* message, int key) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
        } 
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    scanf("%[^\n]s", message);

    printf("Enter encryption key: ");
    scanf("%d", &key);

    printf("\nOriginal message: %s\n", message);

    // Encrypt the message
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}