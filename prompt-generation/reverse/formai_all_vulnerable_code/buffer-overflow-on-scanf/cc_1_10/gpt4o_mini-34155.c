//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *message, int key);
void decrypt(char *message, int key);
void displayWelcomeMessage();
void displayGoodbyeMessage();

int main() {
    displayWelcomeMessage();

    char message[256];  // Buffer for the message
    int key;
    int choice;

    printf("\nEnter your message (max 255 characters): ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove the newline character

    printf("\nEnter the encryption key (0-25): ");
    scanf("%d", &key);
    key = key % 26; // Normalize key to be within range

    printf("\nWhat would you like to do?\n1. Encrypt\n2. Decrypt\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nLet's encrypt your message! 🎉\n");
        encrypt(message, key);
    } else if (choice == 2) {
        printf("\nLet's decrypt your message! 🔍\n");
        decrypt(message, key);
    } else {
        printf("\nOops! That's not a valid option. Please restart the program. 😊\n");
    }

    displayGoodbyeMessage();
    return 0;
}

void encrypt(char *message, int key) {
    char encryptedMessage[256];
    int i;

    for (i = 0; message[i] != '\0'; i++) {
        char currentChar = message[i];

        // Encrypt only alphabetic characters
        if (currentChar >= 'a' && currentChar <= 'z') {
            encryptedMessage[i] = (currentChar - 'a' + key) % 26 + 'a';
        } else if (currentChar >= 'A' && currentChar <= 'Z') {
            encryptedMessage[i] = (currentChar - 'A' + key) % 26 + 'A';
        } else {
            encryptedMessage[i] = currentChar; // Keep other characters unchanged
        }
    }
    encryptedMessage[i] = '\0'; // Null-terminate the string

    printf("\n🎊 Encrypted Message: %s 🎊\n", encryptedMessage);
}

void decrypt(char *message, int key) {
    char decryptedMessage[256];
    int i;

    for (i = 0; message[i] != '\0'; i++) {
        char currentChar = message[i];

        // Decrypt only alphabetic characters
        if (currentChar >= 'a' && currentChar <= 'z') {
            decryptedMessage[i] = (currentChar - 'a' - key + 26) % 26 + 'a'; // Add 26 to avoid negative
        } else if (currentChar >= 'A' && currentChar <= 'Z') {
            decryptedMessage[i] = (currentChar - 'A' - key + 26) % 26 + 'A'; // Add 26 to avoid negative
        } else {
            decryptedMessage[i] = currentChar; // Keep other characters unchanged
        }
    }
    decryptedMessage[i] = '\0'; // Null-terminate the string

    printf("\n🔓 Decrypted Message: %s 🔓\n", decryptedMessage);
}

void displayWelcomeMessage() {
    printf("🌈 Welcome to the Happy Encryption Program! 🌈\n");
    printf("Let's make your messages more fun and secure! 😊\n");
}

void displayGoodbyeMessage() {
    printf("\n🎉 Thank you for using the Happy Encryption Program! 🎉\n");
    printf("Have a fantastic day! 🌟\n");
}