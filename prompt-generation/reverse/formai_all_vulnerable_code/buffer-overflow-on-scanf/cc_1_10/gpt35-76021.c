//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define LENGTH 100 // Maximum length of the message
#define KEYLENGTH 16 // Length of the encryption key

// Encrypt function
void encrypt(char *message, char *key) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    int i, j;

    // Loop through each character of the message
    for (i = 0, j = 0; i < messageLength; i++, j++) {
        // Handle key length
        if (j >= keyLength) {
            j = 0;
        }

        // Encrypt the character
        message[i] = (message[i] + key[j]) % 256;
    }
}

// Decrypt function
void decrypt(char *message, char *key) {
    int messageLength = strlen(message);
    int keyLength = strlen(key);
    int i, j;

    // Loop through each character of the message
    for (i = 0, j = 0; i < messageLength; i++, j++) {
        // Handle key length
        if (j >= keyLength) {
            j = 0;
        }

        // Decrypt the character
        message[i] = (message[i] - key[j] + 256) % 256;
    }
}

int main() {
    char message[LENGTH];
    char key[KEYLENGTH];
    int choice;

    // Get user input
    printf("Enter a message (up to %d characters): ", LENGTH-1);
    fgets(message, LENGTH, stdin);
    printf("Enter a key (must be %d characters): ", KEYLENGTH);
    fgets(key, KEYLENGTH, stdin);

    // Remove newline characters
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    // Generate random key if none provided
    if (strlen(key) == 0) {
        srand(time(NULL));
        int i;
        for (i = 0; i < KEYLENGTH; i++) {
            key[i] = rand() % 256;
        }
    }

    // Menu
    printf("Select an option:\n");
    printf("1. Encrypt message with given key.\n");
    printf("2. Decrypt message with given key.\n");
    printf("3. Generate random key and encrypt message.\n");
    printf("4. Generate random key and decrypt message.\n");
    printf("Choice: ");
    scanf("%d", &choice);

    // Encrypt or decrypt based on user input
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
            srand(time(NULL));
            int i;
            for (i = 0; i < KEYLENGTH; i++) {
                key[i] = rand() % 256;
            }
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            printf("Generated key: ");
            for (i = 0; i < KEYLENGTH; i++) {
                printf("%02X", key[i]);
            }
            printf("\n");
            break;
        case 4:
            srand(time(NULL));
            for (i = 0; i < KEYLENGTH; i++) {
                key[i] = rand() % 256;
            }
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            printf("Generated key: ");
            for (i = 0; i < KEYLENGTH; i++) {
                printf("%02X", key[i]);
            }
            printf("\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}