//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function for encryption using Caesar cipher
void encrypt(char *text, int shift, char *result) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Encrypt uppercase characters
        if (ch >= 'A' && ch <= 'Z') {
            result[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase characters
        else if (ch >= 'a' && ch <= 'z') {
            result[i] = (ch + shift - 'a') % 26 + 'a';
        } else {
            // Non-alphabetical characters are not changed
            result[i] = ch;
        }
    }
    result[strlen(text)] = '\0'; // Null-terminate the string
}

// Function for decryption using Caesar cipher
void decrypt(char *text, int shift, char *result) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Decrypt uppercase characters
        if (ch >= 'A' && ch <= 'Z') {
            result[i] = (ch - shift - 'A' + 26) % 26 + 'A'; // +26 to ensure no negative index
        }
        // Decrypt lowercase characters
        else if (ch >= 'a' && ch <= 'z') {
            result[i] = (ch - shift - 'a' + 26) % 26 + 'a'; // +26 to ensure no negative index
        } else {
            // Non-alphabetical characters are not changed
            result[i] = ch;
        }
    }
    result[strlen(text)] = '\0'; // Null-terminate the string
}

// Function to get user input for text
void getInput(char *text, int length) {
    printf("Enter text (max %d characters): ", length - 1);
    fgets(text, length, stdin);
    text[strcspn(text, "\n")] = 0; // Remove trailing newline
}

int main() {
    char text[256];
    char encryptedText[256];
    char decryptedText[256];
    int shift;

    // Get user input
    getInput(text, sizeof(text));

    // Get shift value
    printf("Enter shift (1-25): ");
    scanf("%d", &shift);
    
    // Validating shift value
    if (shift < 1 || shift > 25) {
        fprintf(stderr, "Invalid shift value! Please enter a value between 1 and 25.\n");
        exit(EXIT_FAILURE);
    }

    // Encrypt the input text
    encrypt(text, shift, encryptedText);
    printf("Encrypted text: %s\n", encryptedText);

    // Decrypt the encrypted text
    decrypt(encryptedText, shift, decryptedText);
    printf("Decrypted text: %s\n", decryptedText);

    return 0;
}