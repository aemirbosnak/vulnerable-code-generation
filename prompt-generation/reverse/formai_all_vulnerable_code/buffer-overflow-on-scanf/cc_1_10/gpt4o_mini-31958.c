//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

void encrypt(char *text, int shift) {
    char *encrypted_text = (char *)malloc(strlen(text) + 1);
    if (encrypted_text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (ch >= 'a' && ch <= 'z') {
            encrypted_text[i] = (ch - 'a' + shift) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            encrypted_text[i] = (ch - 'A' + shift) % 26 + 'A';
        } else {
            encrypted_text[i] = ch; // Non-alphabetic characters remain unchanged
        }
    }
    encrypted_text[strlen(text)] = '\0'; // Null-terminate the string

    printf("Encrypted text: %s\n", encrypted_text);
    free(encrypted_text);
}

void decrypt(char *text, int shift) {
    char *decrypted_text = (char *)malloc(strlen(text) + 1);
    if (decrypted_text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        if (ch >= 'a' && ch <= 'z') {
            decrypted_text[i] = (ch - 'a' - shift + 26) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            decrypted_text[i] = (ch - 'A' - shift + 26) % 26 + 'A';
        } else {
            decrypted_text[i] = ch; // Non-alphabetic characters remain unchanged
        }
    }
    decrypted_text[strlen(text)] = '\0'; // Null-terminate the string

    printf("Decrypted text: %s\n", decrypted_text);
    free(decrypted_text);
}

int main() {
    char input[MAX_LENGTH];
    int shift = 0;

    printf("Enter the shift value (1-25): ");
    if (scanf("%d", &shift) != 1 || shift < 1 || shift > 25) {
        fprintf(stderr, "Invalid shift value. Please enter a number between 1 and 25.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the text to be encrypted: ");
    // Clear input buffer before reading the string
    getchar(); // Ignore the newline after the number input
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    // Remove the newline character if present
    input[strcspn(input, "\n")] = 0;

    printf("Original text: %s\n", input);

    encrypt(input, shift);
    decrypt(input, shift);

    return EXIT_SUCCESS;
}