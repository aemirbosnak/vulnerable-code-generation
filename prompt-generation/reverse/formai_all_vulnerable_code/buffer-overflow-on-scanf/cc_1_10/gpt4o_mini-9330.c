//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: light-weight
#include <stdio.h>
#include <string.h>

// Function to encrypt text using Caesar cipher
void encrypt(char *text, int shift) {
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch + shift - 'a') % 26 + 'a';
        }
        text[i] = ch;
    }
}

// Function to decrypt text using Caesar cipher
void decrypt(char *text, int shift) {
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - shift + 26 - 'A') % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - shift + 26 - 'a') % 26 + 'a';
        }
        text[i] = ch;
    }
}

int main() {
    char text[100];
    int shift, choice;

    printf("Simple Caesar Cipher \n");
    printf("---------------------\n");
    
    while (1) {
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);
        
        if (choice == 3) {
            printf("Exiting the program.\n");
            break;
        }

        printf("Enter the message (max 99 characters): ");
        scanf(" %[^\n]", text);  // Read a line of text.

        printf("Enter shift value (1-25): ");
        scanf("%d", &shift);
        shift = shift % 26;  // Ensure the shift is within 0-25

        switch (choice) {
            case 1:
                encrypt(text, shift);
                printf("Encrypted message: %s\n", text);
                break;
            case 2:
                decrypt(text, shift);
                printf("Decrypted message: %s\n", text);
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }
    
    return 0;
}