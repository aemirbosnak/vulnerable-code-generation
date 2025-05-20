//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char offset = isupper(text[i]) ? 'A' : 'a';
        if (isalpha(text[i])) {
            text[i] = (text[i] - offset + shift) % 26 + offset;
        }
    }
}

void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char offset = isupper(text[i]) ? 'A' : 'a';
        if (isalpha(text[i])) {
            text[i] = (text[i] - offset - shift + 26) % 26 + offset;
        }
    }
}

void get_input(char *buffer, size_t size) {
    printf("Enter your message: ");
    if (fgets(buffer, size, stdin) == NULL) {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character
}

int main() {
    char message[256];
    int shift;

    printf("Welcome to the Simple Caesar Cipher!\n");
    get_input(message, sizeof(message));

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);

    // Validating shift value
    if (shift < 1 || shift > 25) {
        fprintf(stderr, "Shift must be between 1 and 25!\n");
        return EXIT_FAILURE;
    }

    // Encrypt the message
    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, shift);
    printf("Decrypted message: %s\n", message);

    return EXIT_SUCCESS;
}