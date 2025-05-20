//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *text, int shift) {
    int i;
    char result[strlen(text) + 1];  // Store encrypted text

    for (i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        // Encrypt uppercase characters
        if (c >= 'A' && c <= 'Z') {
            result[i] = (c + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase characters
        else if (c >= 'a' && c <= 'z') {
            result[i] = (c + shift - 'a') % 26 + 'a';
        } else {
            result[i] = c; // Non-alphabetic characters are unchanged
        }
    }
    result[i] = '\0'; // Null-terminate the encrypted string

    printf("Encrypted text: %s\n", result);
}

void decrypt(char *text, int shift) {
    int i;
    char result[strlen(text) + 1];  // Store decrypted text

    for (i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        // Decrypt uppercase characters
        if (c >= 'A' && c <= 'Z') {
            result[i] = (c - shift - 'A' + 26) % 26 + 'A'; // +26 to handle negative
        }
        // Decrypt lowercase characters
        else if (c >= 'a' && c <= 'z') {
            result[i] = (c - shift - 'a' + 26) % 26 + 'a'; // +26 to handle negative
        } else {
            result[i] = c; // Non-alphabetic characters are unchanged
        }
    }
    result[i] = '\0'; // Null-terminate the decrypted string

    printf("Decrypted text: %s\n", result);
}

int main() {
    char text[100];
    int shift;
    int choice;

    printf("Caesar Cipher Implementation\n");
    printf("-----------------------------\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Input validation for choice
    if (choice != 1 && choice != 2) {
        printf("Invalid choice! Please run the program again.\n");
        return 1;
    }

    printf("Enter a string (up to 99 characters): ");
    getchar(); // Clear the newline character from input buffer
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character

    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);
    
    // Input validation for shift
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value! Please use a value between 1 and 25.\n");
        return 1;
    }

    if (choice == 1) {
        encrypt(text, shift);
    } else {
        decrypt(text, shift);
    }

    return 0;
}