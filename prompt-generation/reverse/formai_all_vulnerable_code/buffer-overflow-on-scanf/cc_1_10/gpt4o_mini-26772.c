//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

// Function to encrypt the given text using Caesar Cipher
void encrypt(char *text, int shift) {
    // Traverse through the text
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        
        // Check for uppercase letters
        if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + shift) % 26 + 'A';
        } 
        // Check for lowercase letters
        else if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt the given text using Caesar Cipher
void decrypt(char *text, int shift) {
    // Traverse through the text
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        // Check for uppercase letters
        if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' - shift + 26) % 26 + 'A'; // Add 26 to avoid negative values
        } 
        // Check for lowercase letters
        else if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' - shift + 26) % 26 + 'a'; // Add 26 to avoid negative values
        }
    }
}

// Function to display the menu options
void displayMenu() {
    printf("\n=== Caesar Cipher Encryption Program ===\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("=========================================\n");
}

// Main function
int main() {
    char text[MAX_LEN];
    int choice, shift;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 2) {
            printf("Invalid choice! Please select again.\n");
            continue;
        }

        printf("Enter the message (up to %d characters): ", MAX_LEN - 1);
        getchar(); // Clear the newline character from the buffer
        fgets(text, MAX_LEN, stdin);
        text[strcspn(text, "\n")] = 0; // Remove the newline character

        printf("Enter the shift value (1-25): ");
        scanf("%d", &shift);
        shift = shift % 26; // Normalize shift value

        if (choice == 1) {
            encrypt(text, shift);
            printf("Encrypted message: %s\n", text);
        } else if (choice == 2) {
            decrypt(text, shift);
            printf("Decrypted message: %s\n", text);
        }
    }

    return 0;
}