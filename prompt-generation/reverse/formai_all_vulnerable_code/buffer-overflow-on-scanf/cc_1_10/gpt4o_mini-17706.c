//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024

// Function prototypes
void encrypt(char *text, int shift);
void decrypt(char *text, int shift);
void display_menu();
int get_shift_value();
void sanitize_input(char *input);

int main() {
    char text[MAX_TEXT_LENGTH];
    int shift, choice;

    while (1) {
        display_menu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar();  // clear the newline character from the buffer

        if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter the text to encrypt: ");
                fgets(text, MAX_TEXT_LENGTH, stdin);
                sanitize_input(text);
                shift = get_shift_value();
                encrypt(text, shift);
                printf("Encrypted text: %s\n", text);
                break;

            case 2:
                printf("Enter the text to decrypt: ");
                fgets(text, MAX_TEXT_LENGTH, stdin);
                sanitize_input(text);
                shift = get_shift_value();
                decrypt(text, shift);
                printf("Decrypted text: %s\n", text);
                break;

            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
                break;
        }
    }

    return 0;
}

// Function to encrypt the text using Caesar cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            text[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            text[i] = (ch - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt the text using Caesar cipher
void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            text[i] = (ch - 'A' - shift + 26) % 26 + 'A'; // +26 to handle negative shifts
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            text[i] = (ch - 'a' - shift + 26) % 26 + 'a'; // +26 to handle negative shifts
        }
    }
}

// Function to display the menu options
void display_menu() {
    printf("\n--- Caesar Cipher Encryption/Decryption ---\n");
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
    printf("3. Exit\n");
}

// Function to get a valid shift value from the user
int get_shift_value() {
    int shift;
    printf("Enter the shift value (0-25): ");
    scanf("%d", &shift);
    while (shift < 0 || shift > 25) {
        printf("Invalid shift value. Please enter a value between 0 and 25: ");
        scanf("%d", &shift);
    }
    return shift;
}

// Function to sanitize string input by removing the newline character
void sanitize_input(char *input) {
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }
}