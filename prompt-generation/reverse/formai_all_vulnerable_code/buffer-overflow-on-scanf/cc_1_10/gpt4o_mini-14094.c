//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *text, int shift) {
    char *result = text; // We will modify the text in place

    for (int i = 0; result[i] != '\0'; i++) {
        // Check if the character is an uppercase letter
        if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = ((result[i] - 'A' + shift) % 26) + 'A';
        }
        // Check if the character is a lowercase letter
        else if (result[i] >= 'a' && result[i] <= 'z') {
            result[i] = ((result[i] - 'a' + shift) % 26) + 'a';
        }
        // Non-alphabetical characters remain unchanged
    }
}

void decrypt(char *text, int shift) {
    char *result = text; // We will modify the text in place

    for (int i = 0; result[i] != '\0'; i++) {
        // Check if the character is an uppercase letter
        if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] = ((result[i] - 'A' - shift + 26) % 26) + 'A';
        }
        // Check if the character is a lowercase letter
        else if (result[i] >= 'a' && result[i] <= 'z') {
            result[i] = ((result[i] - 'a' - shift + 26) % 26) + 'a';
        }
        // Non-alphabetical characters remain unchanged
    }
}

int main() {
    char text[256];
    int shift;
    int choice;

    printf("Welcome to the Caesar Cipher Encryption Program!\n");
    printf("Please enter the text you want to encrypt or decrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove the newline character

    do {
        printf("\nChoose an operation:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please enter a value between 1 and 25.\n");
                } else {
                    encrypt(text, shift);
                    printf("Encrypted Text: %s\n", text);
                }
                break;

            case 2:
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please enter a value between 1 and 25.\n");
                } else {
                    decrypt(text, shift);
                    printf("Decrypted Text: %s\n", text);
                }
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select 1, 2, or 3.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}