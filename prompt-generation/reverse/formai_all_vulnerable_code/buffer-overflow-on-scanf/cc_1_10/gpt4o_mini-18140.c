//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

// Function to encrypt the text using Caesar Cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
    }
}

// Function to decrypt the text
void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' - shift + 26) % 26 + 'A';
        }
    }
}

// Function to display menu options
void displayMenu() {
    printf("****************************\n");
    printf("Welcome to Simple C Encryptor\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("****************************\n");
}

// Main function where program execution begins
int main() {
    char text[MAX_SIZE];
    int shift, choice;

    while (1) {
        displayMenu();
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from buffer

        if (choice == 1) {
            printf("Enter the text to encrypt: ");
            fgets(text, MAX_SIZE, stdin);
            text[strcspn(text, "\n")] = 0; // Remove the newline character
            
            printf("Enter the shift value (1-25): ");
            scanf("%d", &shift);
            shift = shift % 26; // Normalize shift

            encrypt(text, shift);
            printf("Encrypted Text: %s\n", text);
        } else if (choice == 2) {
            printf("Enter the text to decrypt: ");
            fgets(text, MAX_SIZE, stdin);
            text[strcspn(text, "\n")] = 0; // Remove the newline character
            
            printf("Enter the shift value (1-25): ");
            scanf("%d", &shift);
            shift = shift % 26; // Normalize shift

            decrypt(text, shift);
            printf("Decrypted Text: %s\n", text);
        } else if (choice == 3) {
            printf("Exiting the program. Thank you!\n");
            break;
        } else {
            printf("Invalid option, please try again!\n");
        }
    }

    return 0;
}