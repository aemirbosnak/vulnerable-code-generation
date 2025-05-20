//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024
#define SHIFT 4

void encrypt(char *text, char *encryptedText) {
    int i = 0;
    while (text[i] != '\0' && i < MAX_TEXT_LENGTH) {
        // Encrypt character by shifting it
        encryptedText[i] = text[i] + SHIFT;
        i++;
    }
    encryptedText[i] = '\0'; // Null-terminate the encrypted string
}

void decrypt(char *encryptedText, char *decryptedText) {
    int i = 0;
    while (encryptedText[i] != '\0' && i < MAX_TEXT_LENGTH) {
        // Decrypt character by shifting it back
        decryptedText[i] = encryptedText[i] - SHIFT;
        i++;
    }
    decryptedText[i] = '\0'; // Null-terminate the decrypted string
}

void displayMenu() {
    printf("*******************************************\n");
    printf("              C Encryption Tool           \n");
    printf("*******************************************\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("*******************************************\n");
    printf("Please enter your choice: ");
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char encryptedText[MAX_TEXT_LENGTH];
    char decryptedText[MAX_TEXT_LENGTH];
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        getchar();  // consume newline character after entering choice

        switch (choice) {
            case 1:
                printf("Enter the text to encrypt: ");
                fgets(text, MAX_TEXT_LENGTH, stdin);
                // Remove newline character if present
                text[strcspn(text, "\n")] = 0;
                encrypt(text, encryptedText);
                printf("Encrypted text: %s\n", encryptedText);
                break;

            case 2:
                printf("Enter the text to decrypt: ");
                fgets(encryptedText, MAX_TEXT_LENGTH, stdin);
                // Remove newline character if present
                encryptedText[strcspn(encryptedText, "\n")] = 0;
                decrypt(encryptedText, decryptedText);
                printf("Decrypted text: %s\n", decryptedText);
                break;

            case 3:
                printf("Exiting the Encryption Tool. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}