//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

void encrypt(char *text, int shift);
void decrypt(char *text, int shift);
void print_menu();
int get_choice();

int main() {
    char text[MAX_LENGTH];
    int shift, choice;

    printf("Welcome to the Shape-Shifting Encryption Program!\n");

    while (1) {
        print_menu();
        choice = get_choice();

        switch (choice) {
            case 1:
                // Input text
                printf("Enter text to encrypt: ");
                getchar(); // Clear newline
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline

                // Input shift
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Shift must be between 1 and 25\n");
                    break;
                }

                // Encrypt
                encrypt(text, shift);
                printf("Encrypted text: %s\n", text);
                break;

            case 2:
                // Input text
                printf("Enter text to decrypt: ");
                getchar(); // Clear newline
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline

                // Input shift
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Shift must be between 1 and 25\n");
                    break;
                }

                // Decrypt
                decrypt(text, shift);
                printf("Decrypted text: %s\n", text);
                break;

            case 3:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        if (ch >= 'a' && ch <= 'z') {
            text[i] = (ch + shift - 'a') % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            text[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Non-alphabetic characters remain unchanged
    }
}

void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        if (ch >= 'a' && ch <= 'z') {
            text[i] = (ch - shift + 26 - 'a') % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            text[i] = (ch - shift + 26 - 'A') % 26 + 'A';
        }
        // Non-alphabetic characters remain unchanged
    }
}

void print_menu() {
    printf("\n--- Menu ---\n");
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
    printf("3. Exit program\n");
    printf("Enter your choice: ");
}

int get_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}