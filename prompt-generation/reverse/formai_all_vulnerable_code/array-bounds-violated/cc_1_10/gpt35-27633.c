//FormAI DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using the given key
void encrypt(char *message, char *key) {
    int msgLen = strlen(message), keyLen = strlen(key), i, j;
    char newKey[msgLen];

    // Generate a new key by repeating the original key until it matches the message length
    for (i = 0, j = 0; i < msgLen; ++i, ++j) {
        if (j == keyLen) j = 0;
        newKey[i] = key[j];
    }
    newKey[i] = '\0';

    // Perform XOR operation on each character of the message with the corresponding character of the new key
    for (i = 0; i < msgLen; ++i) {
        message[i] ^= newKey[i];
    }
}

// Function to decrypt the message using the given key
void decrypt(char *message, char *key) {
    encrypt(message, key); // decryption is the same as encryption with the same key
}

int main() {
    char message[100], key[100];
    int choice;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    message[strcspn(message, "\n")] = '\0'; // remove newline character

    printf("Enter key: ");
    fgets(key, 100, stdin); 
    key[strcspn(key, "\n")] = '\0'; // remove newline character

    do {
        printf("\nSelect operation\n");
        printf("1. Encrypt message\n");
        printf("2. Decrypt message\n");
        printf("3. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                encrypt(message, key);
                printf("Encrypted message: %s\n", message);
                break;
            case 2:
                decrypt(message, key);
                printf("Decrypted message: %s\n", message);
                break;
            case 3:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);

    return 0;
}