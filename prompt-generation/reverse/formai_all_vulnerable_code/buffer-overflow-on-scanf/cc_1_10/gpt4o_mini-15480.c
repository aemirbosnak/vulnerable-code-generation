//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
char *encrypt(const char *text, int shift);
char *decrypt(const char *text, int shift);
int is_valid_shift(int shift);

// Main function
int main() {
    char text[256];
    int shift;
    char choice;

    printf("Welcome to the Dynamic C Encryption Program!\n");

    // Input the text to encrypt
    printf("Enter the text to encrypt (max 255 characters): ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character

    // Input shift value
    do {
        printf("Enter the shift value (1-25): ");
        scanf("%d", &shift);
    } while (!is_valid_shift(shift));

    // Encryption
    char *encrypted_text = encrypt(text, shift);
    printf("Encrypted Text: %s\n", encrypted_text);

    // Decryption
    printf("Do you want to decrypt the text? (y/n): ");
    getchar(); // To consume newline character
    choice = getchar();

    if (choice == 'y' || choice == 'Y') {
        char *decrypted_text = decrypt(encrypted_text, shift);
        printf("Decrypted Text: %s\n", decrypted_text);
        free(decrypted_text);
    } else {
        printf("You chose not to decrypt the text.\n");
    }

    // Freeing the encrypted text
    free(encrypted_text);

    printf("Thank you for using the encryption program!\n");
    return 0;
}

// Encrypt function
char *encrypt(const char *text, int shift) {
    int len = strlen(text);
    char *encrypted_text = (char *)malloc(len + 1); // +1 for null terminator

    if (encrypted_text == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < len; i++) {
        char c = text[i];

        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            encrypted_text[i] = (c - base + shift) % 26 + base;
        } else {
            encrypted_text[i] = c; // Non-alphabet characters are not changed
        }
    }

    encrypted_text[len] = '\0'; // Null terminate the string
    return encrypted_text;
}

// Decrypt function
char *decrypt(const char *text, int shift) {
    int len = strlen(text);
    char *decrypted_text = (char *)malloc(len + 1); // +1 for null terminator

    if (decrypted_text == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < len; i++) {
        char c = text[i];

        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            decrypted_text[i] = (c - base - shift + 26) % 26 + base; // +26 to avoid negative
        } else {
            decrypted_text[i] = c; // Non-alphabet characters are not changed
        }
    }

    decrypted_text[len] = '\0'; // Null terminate the string
    return decrypted_text;
}

// Validate the shift input
int is_valid_shift(int shift) {
    return shift >= 1 && shift <= 25;
}