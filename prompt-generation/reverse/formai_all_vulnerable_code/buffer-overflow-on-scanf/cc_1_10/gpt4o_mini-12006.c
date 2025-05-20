//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the text using simple Caesar cipher method
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char current = text[i];

        // Encrypt uppercase letters
        if (current >= 'A' && current <= 'Z') {
            text[i] = (current + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (current >= 'a' && current <= 'z') {
            text[i] = (current + shift - 'a') % 26 + 'a';
        }
    }
}

// Function to decrypt the text using simple Caesar cipher method
void decrypt(char *text, int shift) {
    encrypt(text, 26 - (shift % 26)); // Decrypt by shifting backwards
}

// Function to find the length of the text
int findLength(char *text) {
    return strlen(text);
}

// Function to get user input
void getUserInput(char *buffer, int size) {
    printf("Enter text to encrypt/decrypt: ");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

// Function to display menu and get user's choice
int displayMenu() {
    int choice;
    printf("\nCeasar Cipher Encryption Program\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume newline character left in buffer
    return choice;
}

// Function to execute the chosen operation
void executeOperation(int choice) {
    char text[256];
    int shift;

    switch (choice) {
        case 1:
            // Encrypt
            getUserInput(text, sizeof(text));
            printf("Enter shift value (1-25): ");
            scanf("%d", &shift);
            getchar(); // Consume newline character left
            encrypt(text, shift);
            printf("Encrypted text: %s\n", text);
            break;
        case 2:
            // Decrypt
            getUserInput(text, sizeof(text));
            printf("Enter shift value (1-25): ");
            scanf("%d", &shift);
            getchar(); // Consume newline character left
            decrypt(text, shift);
            printf("Decrypted text: %s\n", text);
            break;
        case 3:
            // Exit
            printf("Exiting the program. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
    }
}

// Main function to run the program
int main() {
    int choice;

    while (1) {
        choice = displayMenu();
        executeOperation(choice);
    }

    return 0;
}