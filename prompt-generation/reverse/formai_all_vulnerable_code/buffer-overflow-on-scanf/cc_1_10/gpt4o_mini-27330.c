//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the text using Caesar cipher
void caesar_encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalpha(c)) {
            char a = isupper(c) ? 'A' : 'a';
            text[i] = (c - a + shift) % 26 + a;
        }
    }
}

// Function to decrypt the text using Caesar cipher
void caesar_decrypt(char *text, int shift) {
    caesar_encrypt(text, 26 - shift); // Decrypting is just shifting the other way
}

// Function to handle user input safely
void get_input(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // Remove newline character
        }
    } else {
        perror("Input error");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main() {
    const size_t BUFFER_SIZE = 256;
    char text[BUFFER_SIZE];
    int shift;

    printf("Enter the text to encrypt: ");
    get_input(text, BUFFER_SIZE);

    printf("Enter the shift value (1-25): ");
    while (1) {
        if (scanf("%d", &shift) != 1 || shift < 1 || shift > 25) {
            printf("Invalid input. Please enter a valid shift value (1-25): ");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            break;
        }
    }

    // Encrypt the text
    char *text_copy = malloc(BUFFER_SIZE);
    if (text_copy == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    strcpy(text_copy, text);
    caesar_encrypt(text_copy, shift);

    printf("Encrypted text: %s\n", text_copy);

    // Decrypt the text
    caesar_decrypt(text_copy, shift);
    printf("Decrypted text: %s\n", text_copy);

    // Clean up allocated memory
    free(text_copy);
    return 0;
}