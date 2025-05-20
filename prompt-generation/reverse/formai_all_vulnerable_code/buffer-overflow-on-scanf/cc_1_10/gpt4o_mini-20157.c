//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using Caesar Cipher
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        
        message[i] = ch;
    }
}

// Function to decrypt the message using Caesar Cipher
void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        
        message[i] = ch;
    }
}

int main() {
    char message[256];
    int shift;
    int choice;

    printf("Welcome to the Caesar Cipher Program!\n");
    printf("Please enter your message (max 255 characters): ");
    fgets(message, sizeof(message), stdin);
    // Remove newline character from the string if present
    message[strcspn(message, "\n")] = 0;
    
    printf("Enter the shift value (positive or negative): ");
    scanf("%d", &shift);

    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(message, shift);
            printf("Encrypted Message: %s\n", message);
            break;

        case 2:
            decrypt(message, shift);
            printf("Decrypted Message: %s\n", message);
            break;

        default:
            printf("Invalid choice! Please choose 1 or 2.\n");
            break;
    }

    return 0;
}