//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024

void encryptText(const char *input, char *output, int shift);
void decryptText(const char *input, char *output, int shift);
void displayMenu();
void handleUserInput();

int main() {
    handleUserInput();
    return 0;
}

void encryptText(const char *input, char *output, int shift) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        
        if (c >= 'a' && c <= 'z') {
            output[i] = (c - 'a' + shift) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            output[i] = (c - 'A' + shift) % 26 + 'A';
        } else {
            output[i] = c;  // Non-alphabetic characters are not changed
        }
    }
    output[i] = '\0';  // Null-terminate the output string
}

void decryptText(const char *input, char *output, int shift) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        
        if (c >= 'a' && c <= 'z') {
            output[i] = (c - 'a' - shift + 26) % 26 + 'a';  // +26 to handle negative shift
        } else if (c >= 'A' && c <= 'Z') {
            output[i] = (c - 'A' - shift + 26) % 26 + 'A';
        } else {
            output[i] = c;  // Non-alphabetic characters are not changed
        }
    }
    output[i] = '\0';  // Null-terminate the output string
}

void displayMenu() {
    printf("=== Caesar Cipher Tool ===\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("==========================\n");
}

void handleUserInput() {
    int choice, shift;
    char input[MAX_TEXT_LENGTH];
    char output[MAX_TEXT_LENGTH];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character after number input

        if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (choice == 1) {
            printf("Enter text to encrypt: ");
            fgets(input, MAX_TEXT_LENGTH, stdin);
            input[strcspn(input, "\n")] = 0;  // Remove newline character

            printf("Enter shift value (1-25): ");
            scanf("%d", &shift);
            getchar();  // Consume newline character

            if (shift < 1 || shift > 25) {
                printf("Invalid shift value. Please enter a value between 1 and 25.\n");
                continue;
            }

            encryptText(input, output, shift);
            printf("Encrypted text: %s\n", output);
        } else if (choice == 2) {
            printf("Enter text to decrypt: ");
            fgets(input, MAX_TEXT_LENGTH, stdin);
            input[strcspn(input, "\n")] = 0;  // Remove newline character

            printf("Enter shift value (1-25): ");
            scanf("%d", &shift);
            getchar();  // Consume newline character

            if (shift < 1 || shift > 25) {
                printf("Invalid shift value. Please enter a value between 1 and 25.\n");
                continue;
            }

            decryptText(input, output, shift);
            printf("Decrypted text: %s\n", output);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}