//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 5
#define MAX_MESSAGE_LENGTH 256
#define SHIFT 3 // Shift value for Caesar Cipher

void encrypt(const char *message, char *encryptedMessage) {
    for (int i = 0; message[i] != '\0'; i++) {
        char c = message[i];
        // Encrypt alphabetic characters only
        if (c >= 'A' && c <= 'Z') {
            encryptedMessage[i] = (c - 'A' + SHIFT) % 26 + 'A';
        } else if (c >= 'a' && c <= 'z') {
            encryptedMessage[i] = (c - 'a' + SHIFT) % 26 + 'a';
        } else {
            encryptedMessage[i] = c; // Non-alphabetic characters remain unchanged
        }
    }
    encryptedMessage[strlen(message)] = '\0'; // Null-terminate the encrypted string
}

void decrypt(const char *encryptedMessage, char *decryptedMessage) {
    for (int i = 0; encryptedMessage[i] != '\0'; i++) {
        char c = encryptedMessage[i];
        // Decrypt alphabetic characters only
        if (c >= 'A' && c <= 'Z') {
            decryptedMessage[i] = (c - 'A' - SHIFT + 26) % 26 + 'A'; // +26 to handle negative values
        } else if (c >= 'a' && c <= 'z') {
            decryptedMessage[i] = (c - 'a' - SHIFT + 26) % 26 + 'a'; // +26 to handle negative values
        } else {
            decryptedMessage[i] = c; // Non-alphabetic characters remain unchanged
        }
    }
    decryptedMessage[strlen(encryptedMessage)] = '\0'; // Null-terminate the decrypted string
}

void displayInstructions() {
    printf("\n=== Caesar Cipher Encryption/Decryption ===\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("=============================================\n");
}

int main() {
    // Store messages for multiple users
    char messages[MAX_USERS][MAX_MESSAGE_LENGTH];
    char encryptedMessages[MAX_USERS][MAX_MESSAGE_LENGTH];
    char decryptedMessages[MAX_USERS][MAX_MESSAGE_LENGTH];

    int userCount = 0;
    int choice;

    while (1) {
        displayInstructions();
        printf("Select an option (1-3): ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        if (choice == 3) {
            printf("Exiting program.\n");
            break;
        }

        if (userCount >= MAX_USERS) {
            printf("Maximum number of users reached. Cannot proceed!\n");
            continue;
        }

        printf("Enter your message: ");
        fgets(messages[userCount], MAX_MESSAGE_LENGTH, stdin);
        messages[userCount][strcspn(messages[userCount], "\n")] = '\0'; // Remove newline

        switch (choice) {
            case 1:
                encrypt(messages[userCount], encryptedMessages[userCount]);
                printf("User %d: Encrypted message: %s\n", userCount + 1, encryptedMessages[userCount]);
                userCount++;
                break;

            case 2:
                decrypt(messages[userCount], decryptedMessages[userCount]);
                printf("User %d: Decrypted message: %s\n", userCount + 1, decryptedMessages[userCount]);
                userCount++;
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}