//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a plaintext using a Caesar cipher
void encrypt(char *plaintext, int shift) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + shift) % 26;
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + shift) % 26;
        }

        plaintext[i] = ch;
    }
}

// Function to decrypt a cipher text using a Caesar cipher
void decrypt(char *ciphertext, int shift) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' - shift + 26) % 26;
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' - shift + 26) % 26;
        }

        ciphertext[i] = ch;
    }
}

// Helper function to get user input safely
void getInput(char *buffer, size_t length) {
    printf("Enter your message: ");
    if (fgets(buffer, length, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        exit(EXIT_FAILURE);
    }
    buffer[strcspn(buffer, "\n")] = '\0';  // Remove newline character
}

int main() {
    char message[256];
    int shift;
    char choice;

    printf("Welcome to the Enigmatic Cipher Utility of Sherlock Holmes!\n");
    printf("You may choose to Encrypt or Decrypt a message.\n");
    printf("Press 'e' to encrypt or 'd' to decrypt: ");
    scanf(" %c", &choice);
    getchar(); // Clear newline character left by scanf

    if (choice == 'e') {
        getInput(message, sizeof(message));
        printf("Please enter the shift value (1-25): ");
        scanf("%d", &shift);
        if (shift < 1 || shift > 25) {
            fprintf(stderr, "Shift value must be between 1 and 25.\n");
            return EXIT_FAILURE;
        }
        encrypt(message, shift);
        printf("Encrypted message: %s\n", message);
    } else if (choice == 'd') {
        getInput(message, sizeof(message));
        printf("Please enter the shift value (1-25): ");
        scanf("%d", &shift);
        if (shift < 1 || shift > 25) {
            fprintf(stderr, "Shift value must be between 1 and 25.\n");
            return EXIT_FAILURE;
        }
        decrypt(message, shift);
        printf("Decrypted message: %s\n", message);
    } else {
        fprintf(stderr, "Invalid choice! Please use 'e' for encrypt or 'd' for decrypt.\n");
        return EXIT_FAILURE;
    }

    printf("Thank you for using the Enigmatic Cipher Utility. Until next time, good detective work!\n");
    return EXIT_SUCCESS;
}