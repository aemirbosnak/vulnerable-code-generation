//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Artistic Preprocessor Directives
#define MAX_TEXT_LENGTH 1024
#define SHIFT 3

// Function Prototypes
void encrypt_caesar(char *text, int shift);
void decrypt_caesar(char *text, int shift);
void display_menu();
void get_input(char *buffer, size_t size);

// Main function
int main() {
    char text[MAX_TEXT_LENGTH];
    int choice;

    // Display the welcome message
    printf("****************************************\n");
    printf("*          Welcome to CryptoArt!       *\n");
    printf("****************************************\n\n");

    // Infinite loop for menu display
    while (1) {
        display_menu();
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter text to encrypt: ");
                get_input(text, sizeof(text));
                encrypt_caesar(text, SHIFT);
                printf("Encrypted Text: %s\n", text);
                break;
            case 2:
                printf("Enter text to decrypt: ");
                get_input(text, sizeof(text));
                decrypt_caesar(text, SHIFT);
                printf("Decrypted Text: %s\n", text);
                break;
            case 3:
                printf("Exiting... Thank you for using CryptoArt!\n");
                return 0;
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}

// Function to encrypt text using Caesar Cipher
void encrypt_caesar(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + shift) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + shift) % 26 + 'A';
        }
    }
}

// Function to decrypt text using Caesar Cipher
void decrypt_caesar(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' - shift + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' - shift + 26) % 26 + 'A';
        }
    }
}

// Function to display the menu
void display_menu() {
    printf("****** CryptoArt Menu ******\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
}

// Function to get input safely
void get_input(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin)) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character if present
    } else {
        buffer[0] = '\0'; // Handle input error
    }
}