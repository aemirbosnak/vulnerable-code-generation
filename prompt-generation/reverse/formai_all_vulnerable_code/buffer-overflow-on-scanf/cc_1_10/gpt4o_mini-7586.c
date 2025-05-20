//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 256

// Function prototypes
void encrypt(char *message, int shift);
void decrypt(char *message, int shift);
void get_message(char *message);

int main() {
    char message[MAX_MSG_LEN];
    int shift;
    int choice;

    printf("🎉 Welcome to the Caesar Cipher Encryptor/Decryptor! 🎉\n");
    printf("Choose your option:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("Enter your choice (1 or 2): ");
    
    if (scanf("%d", &choice) != 1 || (choice < 1 || choice > 2)) {
        printf("😱 Invalid choice! Exiting...\n");
        return 1;
    }

    printf("Enter your shift value (1-25): ");
    if (scanf("%d", &shift) != 1 || (shift < 1 || shift > 25)) {
        printf("😱 Invalid shift value! Exiting...\n");
        return 1;
    }
    // Clear the newline character left by scanf
    while (getchar() != '\n');

    get_message(message);

    if (choice == 1) {
        encrypt(message, shift);
        printf("✨ Encrypted Message: %s\n", message);
    } else if (choice == 2) {
        decrypt(message, shift);
        printf("✨ Decrypted Message: %s\n", message);
    }

    printf("🎉 Thank you for using the Caesar Cipher! Goodbye! 🎉\n");
    return 0;
}

// Function to encrypt the message using Caesar cipher
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char c = message[i];

        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            message[i] = (c - 'A' + shift) % 26 + 'A';
        } 
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            message[i] = (c - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char c = message[i];

        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            message[i] = (c - 'A' - shift + 26) % 26 + 'A'; // +26 for negative modulo
        } 
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            message[i] = (c - 'a' - shift + 26) % 26 + 'a'; // +26 for negative modulo
        }
    }
}

// Function to get user input for message
void get_message(char *message) {
    printf("Enter your message (max length %d characters): ", MAX_MSG_LEN - 1);
    fgets(message, MAX_MSG_LEN, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character if exists
}