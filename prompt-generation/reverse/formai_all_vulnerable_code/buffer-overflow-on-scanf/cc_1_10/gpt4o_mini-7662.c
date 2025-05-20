//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

// Function prototypes
void encrypt(char *text, int shift);
void decrypt(char *text, int shift);
void displayMenu();

int main() {
    char inputText[MAX_LENGTH];
    int shift, choice;
    
    printf("** Welcome to the Galactic Encryption System **\n");
    displayMenu();
    
    while (1) {
        printf("Please enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the text to encrypt: ");
                getchar(); // consume newline
                fgets(inputText, MAX_LENGTH, stdin);
                inputText[strcspn(inputText, "\n")] = 0; // Remove newline character
                printf("Enter the shift amount (1-25): ");
                scanf("%d", &shift);
                encrypt(inputText, shift);
                break;

            case 2:
                printf("Enter the text to decrypt: ");
                getchar();
                fgets(inputText, MAX_LENGTH, stdin);
                inputText[strcspn(inputText, "\n")] = 0;
                printf("Enter the shift amount (1-25): ");
                scanf("%d", &shift);
                decrypt(inputText, shift);
                break;

            case 3:
                printf("Exiting the Galactic Encryption System. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void encrypt(char *text, int shift) {
    char encryptedText[MAX_LENGTH];
    int i = 0;
    
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            encryptedText[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            encryptedText[i] = (ch + shift - 'a') % 26 + 'a';
        } else {
            encryptedText[i] = ch; // Non-alphabetic characters remain unchanged
        }
    }
    encryptedText[i] = '\0'; // Null-terminate the string
    printf("Encrypted Text: %s\n", encryptedText);
}

void decrypt(char *text, int shift) {
    char decryptedText[MAX_LENGTH];
    int i = 0;
    
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            decryptedText[i] = (ch - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            decryptedText[i] = (ch - shift - 'a' + 26) % 26 + 'a';
        } else {
            decryptedText[i] = ch; // Non-alphabetic characters remain unchanged
        }
    }
    decryptedText[i] = '\0'; // Null-terminate the string
    printf("Decrypted Text: %s\n", decryptedText);
}

void displayMenu() {
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}