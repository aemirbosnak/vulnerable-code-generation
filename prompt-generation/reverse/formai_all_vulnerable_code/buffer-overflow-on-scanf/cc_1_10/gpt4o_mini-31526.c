//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGE_LENGTH 1024
#define ALPHABET_SIZE 26

// Function to clean the input by removing non-alphabetic characters and converting to lowercase
void clean_input(const char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            output[j++] = tolower(input[i]);
        }
    }
    output[j] = '\0'; // Null-terminate the cleaned string
}

// Function to encrypt the message using a simple Caesar cipher technique
void caesar_cipher_encrypt(const char *message, int shift, char *encrypted) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            encrypted[i] = ((ch - offset + shift) % ALPHABET_SIZE) + offset;
        } else {
            encrypted[i] = ch; // Non-alphabetic characters remain unchanged
        }
    }
}

// Function to decrypt the message using a simple Caesar cipher technique
void caesar_cipher_decrypt(const char *encrypted, int shift, char *decrypted) {
    for (int i = 0; encrypted[i] != '\0'; i++) {
        char ch = encrypted[i];
        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            decrypted[i] = ((ch - offset - shift + ALPHABET_SIZE) % ALPHABET_SIZE) + offset;
        } else {
            decrypted[i] = ch; // Non-alphabetic characters remain unchanged
        }
    }
}

// Main program function
int main() {
    char message[MAX_MESSAGE_LENGTH];
    char cleaned_message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int shift;

    // Get the message from the user
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character

    // Clean the input message
    clean_input(message, cleaned_message);
    printf("Cleaned message: %s\n", cleaned_message);

    // Get the shift value
    printf("Enter a shift value (1-25): ");
    scanf("%d", &shift);
    shift = shift % ALPHABET_SIZE; // Ensure shift is within the alphabet size

    // Encrypt the message
    caesar_cipher_encrypt(cleaned_message, shift, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    caesar_cipher_decrypt(encrypted_message, shift, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}