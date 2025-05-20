//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the input text using Caesar cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            text[i] = (c - base + shift) % 26 + base;
        }
    }
}

// Function to decrypt the input text using Caesar cipher
void decrypt(char *text, int shift) {
    shift = 26 - (shift % 26);  // Adjust shift for decrypting
    encrypt(text, shift);        // Reuse encrypt function with adjusted shift
}

// Function to get the shift value with validation
int get_shift_value() {
    int shift;
    printf("Enter shift value (0-25): ");
    while (1) {
        scanf("%d", &shift);
        if (shift >= 0 && shift <= 25) {
            return shift;
        }
        printf("Invalid shift! Please enter a value between 0 and 25: ");
    }
}

// Function to get the text to encrypt/decrypt
void get_text(char *buffer, int size) {
    printf("Enter the text: ");
    getchar();  // Clear the newline from the buffer
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline character from the end
}

// Main function
int main() {
    char text[256];
    int shift;
    int choice;

    printf("Welcome to the Caesar Cipher Program!\n");
    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    while (1) {
        scanf("%d", &choice);
        if (choice == 1 || choice == 2) {
            break;
        }
        printf("Invalid choice! Please select 1 for Encrypt or 2 for Decrypt: ");
    }

    shift = get_shift_value();
    get_text(text, sizeof(text));

    if (choice == 1) {
        encrypt(text, shift);
        printf("Encrypted text: %s\n", text);
    } else {
        decrypt(text, shift);
        printf("Decrypted text: %s\n", text);
    }

    return 0;
}