//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024

// Function to encrypt text using the Caesar cipher
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
        // Ignore non-alphabetic characters
    }
}

// Function to decrypt text using the Caesar cipher
void decrypt(char *text, int shift) {
    // To decrypt, we can just shift in the opposite direction
    encrypt(text, 26 - (shift % 26));
}

// Function to read text from the user
void read_input(char *buffer, size_t size) {
    printf("Enter text (type 'exit' to quit): ");
    fgets(buffer, size, stdin);
    
    // Remove the newline character from input
    buffer[strcspn(buffer, "\n")] = 0;
}

// Function to handle the menu for the user
void menu() {
    printf("\n--- Caesar Cipher Program ---\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("-----------------------------\n");
}

// Main function to interface with the user
int main() {
    char text[MAX_TEXT_LENGTH];
    int shift;
    int choice;

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from buffer

        switch (choice) {
            case 1:
                printf("Enter shift value (0-25): ");
                scanf("%d", &shift);
                getchar();  // Clear newline character

                read_input(text, MAX_TEXT_LENGTH);
                encrypt(text, shift);                
                printf("Encrypted Text: %s\n", text);
                break;

            case 2:
                printf("Enter shift value (0-25): ");
                scanf("%d", &shift);
                getchar();  // Clear newline character

                read_input(text, MAX_TEXT_LENGTH);
                decrypt(text, shift);
                printf("Decrypted Text: %s\n", text);
                break;

            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}