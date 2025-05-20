//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

// Function to encrypt the input text using Caesar cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

// Function to decrypt the input text using Caesar cipher
void decrypt(char *text, int shift) {
    encrypt(text, 26 - (shift % 26)); // Decrypt by reversing the encryption
}

// Function to display the menu
void displayMenu() {
    printf("Caesar Cipher Encryption Program\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    char text[MAX_LENGTH];
    int shift, choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                printf("Enter the text to encrypt: ");
                fgets(text, MAX_LENGTH, stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline character

                printf("Enter the shift value: ");
                scanf("%d", &shift);
                clearInputBuffer();

                encrypt(text, shift);
                printf("Encrypted text: %s\n", text);
                break;

            case 2:
                printf("Enter the text to decrypt: ");
                fgets(text, MAX_LENGTH, stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline character

                printf("Enter the shift value: ");
                scanf("%d", &shift);
                clearInputBuffer();

                decrypt(text, shift);
                printf("Decrypted text: %s\n", text);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}