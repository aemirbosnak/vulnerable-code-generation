//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

// Function to encrypt the text using a simple shift cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        // Encrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
        // Non-alphabetic characters are not altered
    }
}

// Function to decrypt the text using a simple shift cipher
void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        // Decrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
        }
        // Non-alphabetic characters are not altered
    }
}

// Function to display the menu options to the user
void displayMenu() {
    printf("Mathematical Style Encryption Program\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

// Function to read the user's input
void readInput(char *str, int maxLen) {
    printf("Enter your message: ");
    fgets(str, maxLen, stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline character
}

// Main function to execute the program
int main() {
    char message[MAX_LEN];
    int option;
    int shift;

    do {
        displayMenu();
        scanf("%d", &option);
        getchar();  // Consume newline character left by scanf

        switch (option) {
            case 1: // Encryption option
                printf("Enter the shift value (0-25): ");
                scanf("%d", &shift);
                getchar(); // Consume newline character
                readInput(message, MAX_LEN);
                encrypt(message, shift);
                printf("Encrypted message: %s\n", message);
                break;
            case 2: // Decryption option
                printf("Enter the shift value (0-25): ");
                scanf("%d", &shift);
                getchar(); // Consume newline character
                readInput(message, MAX_LEN);
                decrypt(message, shift);
                printf("Decrypted message: %s\n", message);
                break;
            case 3: // Exit option
                printf("Exiting program...\n");
                break;
            default: // Invalid option
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 3);

    return 0;
}