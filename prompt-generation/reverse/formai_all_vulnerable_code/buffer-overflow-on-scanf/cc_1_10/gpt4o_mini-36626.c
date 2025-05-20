//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

// Function to encrypt the text using Caesar cipher
void encrypt(char *text, int shift) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        text[i] = ch;
    }
}

// Function to decrypt the text using Caesar cipher
void decrypt(char *text, int shift) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        text[i] = ch;
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Caesar Cipher Cryptography ---\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("----------------------------------\n");
    printf("Choose an option: ");
}

// Function to get input from user
void getInput(char *prompt, char *buffer) {
    printf("%s", prompt);
    fgets(buffer, MAX_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = 0;  // Remove newline character
}

// Main function
int main() {
    char text[MAX_LENGTH];
    int shift;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        if (choice == 1) {
            getInput("Enter text to encrypt: ", text);
            getInput("Enter shift value (1-25): ", text + strlen(text) + 1);
            shift = atoi(text + strlen(text) + 1);
            encrypt(text, shift);
            printf("Encrypted Text: %s\n", text);
        } else if (choice == 2) {
            getInput("Enter text to decrypt: ", text);
            getInput("Enter shift value (1-25): ", text + strlen(text) + 1);
            shift = atoi(text + strlen(text) + 1);
            decrypt(text, shift);
            printf("Decrypted Text: %s\n", text);
        } else if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}