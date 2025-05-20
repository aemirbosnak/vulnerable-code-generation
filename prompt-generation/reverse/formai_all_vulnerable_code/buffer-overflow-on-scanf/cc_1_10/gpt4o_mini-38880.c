//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT_LENGTH 1024

// Function to encrypt a text using Caesar Cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        
        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt a text using Caesar Cipher
void decrypt(char *text, int shift) {
    encrypt(text, 26 - shift);  // Decrypting is just encrypting with 26 - shift
}

// Function to get user input
void getInput(char *buffer, int length) {
    printf("Enter the text: ");
    fgets(buffer, length, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character if present
}

// Function to display menu and handle user choices
void menu() {
    char text[MAX_TEXT_LENGTH];
    int shift, choice;

    while (1) {
        printf("\nSimple Caesar Cipher Encryption/Decryption\n");
        printf("1. Encrypt Text\n");
        printf("2. Decrypt Text\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);
        getchar(); // Clear newline left by scanf

        if (choice == 3) {
            printf("Exiting the program.\n");
            break;
        }

        printf("Enter the shift value (1-25): ");
        scanf("%d", &shift);
        getchar(); // Clear newline left by scanf

        if (shift < 1 || shift > 25) {
            printf("Invalid shift value. It should be between 1 and 25.\n");
            continue;
        }

        getInput(text, MAX_TEXT_LENGTH);
        
        switch (choice) {
            case 1:
                encrypt(text, shift);
                printf("Encrypted Text: %s\n", text);
                break;
            case 2:
                decrypt(text, shift);
                printf("Decrypted Text: %s\n", text);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}