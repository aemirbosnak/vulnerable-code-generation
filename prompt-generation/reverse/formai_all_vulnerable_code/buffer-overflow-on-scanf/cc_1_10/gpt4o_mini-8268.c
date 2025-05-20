//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *text, int shift);
void decrypt(char *text, int shift);
void displayMenu();

// Main function - The starting point of the art
int main() {
    char text[100];
    int shift;
    int choice;

    // Display a welcome message
    printf("*****************************\n");
    printf("*       Caesar Cipher       *\n");
    printf("*  Art in every character   *\n");
    printf("*****************************\n");

    // Loop until user chooses to exit
    while (1) {
        displayMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        // Clear the input buffer
        while (getchar() != '\n');

        switch(choice) {
            case 1:
                // Encrypt text
                printf("Enter text to encrypt: ");
                fgets(text, sizeof(text), stdin);
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                encrypt(text, shift);
                break;
            case 2:
                // Decrypt text
                printf("Enter text to decrypt: ");
                fgets(text, sizeof(text), stdin);
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                decrypt(text, shift);
                break;
            case 3:
                // Exit the program
                printf("Thank you for using the Caesar Cipher. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0; // Artistic closure of the main function
}

// Function to encrypt the text
void encrypt(char *text, int shift) {
    char result[100];
    int i, index;

    shift = shift % 26; // Limit the shift between 0-25
    for (i = 0; text[i] != '\0'; ++i) {
        char c = text[i];

        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            index = (c + shift - 'A') % 26 + 'A';
            result[i] = index;
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            index = (c + shift - 'a') % 26 + 'a';
            result[i] = index;
        } else {
            result[i] = c; // Non-alphabet characters remain unchanged
        }
    }
    result[i] = '\0'; // Null terminate the result
    printf("Encrypted text: %s", result);
}

// Function to decrypt the text
void decrypt(char *text, int shift) {
    char result[100];
    int i, index;

    shift = shift % 26; // Limit the shift between 0-25
    for (i = 0; text[i] != '\0'; ++i) {
        char c = text[i];

        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            index = (c - shift - 'A' + 26) % 26 + 'A';
            result[i] = index;
        }
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            index = (c - shift - 'a' + 26) % 26 + 'a';
            result[i] = index;
        } else {
            result[i] = c; // Non-alphabet characters remain unchanged
        }
    }
    result[i] = '\0'; // Null terminate the result
    printf("Decrypted text: %s", result);
}

// Function to display the menu
void displayMenu() {
    printf("\n-----------------------------\n");
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
    printf("3. Exit\n");
    printf("-----------------------------\n");
}