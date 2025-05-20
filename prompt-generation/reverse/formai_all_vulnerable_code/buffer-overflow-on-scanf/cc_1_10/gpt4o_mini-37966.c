//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 256

void encrypt(char *text, int shift) {
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];

        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + shift) % 26 + 'a';
        }
    }
}

void decrypt(char *text, int shift) {
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];

        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

int main() {
    char text[MAX_TEXT_SIZE];
    int shift;
    int choice;

    printf("Welcome to the Caesar Cipher Program!\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);
    
    if (choice != 1 && choice != 2) {
        printf("Invalid choice! Exiting the program.\n");
        return 1;
    }

    printf("Enter the text (max %d characters): ", MAX_TEXT_SIZE - 1);
    getchar(); // Clear the buffer
    fgets(text, MAX_TEXT_SIZE, stdin);
    text[strcspn(text, "\n")] = 0; // Remove the newline character

    printf("Enter the shift value (0-25): ");
    scanf("%d", &shift);
    
    // Normalize shift value
    shift = shift % 26;

    if (choice == 1) {
        printf("Original Text: %s\n", text);
        encrypt(text, shift);
        printf("Encrypted Text: %s\n", text);
    } else if (choice == 2) {
        printf("Encrypted Text: %s\n", text);
        decrypt(text, shift);
        printf("Decrypted Text: %s\n", text);
    }

    return 0;
}