//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For string operations
#include <ctype.h>  // For character handling
#include <stdbool.h>

// Function to encrypt the input text using a simple Caesar Cipher
void encrypt(char *text, int shift) {
    int i;
    char ch;

    for (i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        // Encrypt uppercase letters
        if (isupper(ch)) {
            ch = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(ch)) {
            ch = (ch + shift - 'a') % 26 + 'a';
        }
        
        text[i] = ch;
    }
}

// Function to decrypt the text using a simple Caesar Cipher
void decrypt(char *text, int shift) {
    int i;
    char ch;

    for (i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        // Decrypt uppercase letters
        if (isupper(ch)) {
            ch = (ch - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (islower(ch)) {
            ch = (ch - shift - 'a' + 26) % 26 + 'a';
        }
        
        text[i] = ch;
    }
}

// Function to display the menu
void displayMenu() {
    printf("====== Caesar Cipher Encryption Tool ======\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("============================================\n");
}

// Function to read a line of text from user input
void getInput(char *buffer, size_t size) {
    printf("Enter your message: ");
    fgets(buffer, size, stdin);
    
    // Remove newline character if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

// Main function
int main() {
    char text[256];
    int choice;
    int shift;

    while (true) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf

        switch (choice) {
            case 1: // Encrypt option
                printf("Enter shift value (0-25): ");
                scanf("%d", &shift);
                getchar(); // To consume the newline character

                if (shift < 0 || shift > 25) {
                    printf("Shift value must be between 0 and 25.\n");
                    break;
                }

                getInput(text, sizeof(text));
                encrypt(text, shift);
                printf("Encrypted message: %s\n", text);
                break;
            
            case 2: // Decrypt option
                printf("Enter shift value (0-25): ");
                scanf("%d", &shift);
                getchar(); // To consume the newline character

                if (shift < 0 || shift > 25) {
                    printf("Shift value must be between 0 and 25.\n");
                    break;
                }

                getInput(text, sizeof(text));
                decrypt(text, shift);
                printf("Decrypted message: %s\n", text);
                break;

            case 3: // Exit option
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            
            default:
                printf("Invalid option! Please try again.\n");
        }
        printf("\n");
    }

    return 0; // This line will never be reached
}