//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 1024
#define SHIFT 4

void encrypt(char *text, char *encryptedText) {
    int i;
    for (i = 0; text[i] != '\0' && i < MAX_TEXT_SIZE; i++) {
        // Encrypt only alphabetic characters
        if (text[i] >= 'a' && text[i] <= 'z') {
            encryptedText[i] = ((text[i] - 'a' + SHIFT) % 26) + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            encryptedText[i] = ((text[i] - 'A' + SHIFT) % 26) + 'A';
        } else {
            encryptedText[i] = text[i]; // Non-alphabetic characters remain unchanged
        }
    }
    encryptedText[i] = '\0'; // Null-terminate the string
}

void decrypt(char *encryptedText, char *decryptedText) {
    int i;
    for (i = 0; encryptedText[i] != '\0' && i < MAX_TEXT_SIZE; i++) {
        // Decrypt only alphabetic characters
        if (encryptedText[i] >= 'a' && encryptedText[i] <= 'z') {
            decryptedText[i] = ((encryptedText[i] - 'a' - SHIFT + 26) % 26) + 'a';
        } else if (encryptedText[i] >= 'A' && encryptedText[i] <= 'Z') {
            decryptedText[i] = ((encryptedText[i] - 'A' - SHIFT + 26) % 26) + 'A';
        } else {
            decryptedText[i] = encryptedText[i]; // Non-alphabetic characters remain unchanged
        }
    }
    decryptedText[i] = '\0'; // Null-terminate the string
}

void displayMenu() {
    printf("**** C Encryption Program ****\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    char text[MAX_TEXT_SIZE];
    char encryptedText[MAX_TEXT_SIZE];
    char decryptedText[MAX_TEXT_SIZE];
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume the newline character after choice input

        switch (choice) {
            case 1:
                printf("Enter text to encrypt: ");
                fgets(text, MAX_TEXT_SIZE, stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline character from input
                encrypt(text, encryptedText);
                printf("Encrypted Text: %s\n", encryptedText);
                break;

            case 2:
                printf("Enter text to decrypt: ");
                fgets(encryptedText, MAX_TEXT_SIZE, stdin);
                encryptedText[strcspn(encryptedText, "\n")] = 0; // Remove newline character from input
                decrypt(encryptedText, decryptedText);
                printf("Decrypted Text: %s\n", decryptedText);
                break;

            case 3:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}