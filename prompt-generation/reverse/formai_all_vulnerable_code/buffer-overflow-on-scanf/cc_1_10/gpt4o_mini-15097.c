//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the alphabet size
#define ALPHABET_SIZE 26

// Function to remove non-alphabetic characters and convert to lowercase
void prepare_text(const char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            output[j++] = tolower(input[i]);
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

// Function to create a simple Caesar Cipher encryption
void caesar_cipher(const char *text, int shift, char *encrypted) {
    for (int i = 0; text[i] != '\0'; i++) {
        char base = 'a';
        char encrypted_char = (text[i] - base + shift) % ALPHABET_SIZE + base;
        encrypted[i] = encrypted_char;
    }
    encrypted[strlen(text)] = '\0'; // Null-terminate the encrypted string
}

// Function to decrypt the Caesar Cipher message
void caesar_decipher(const char *text, int shift, char *decrypted) {
    for (int i = 0; text[i] != '\0'; i++) {
        char base = 'a';
        char decrypted_char = (text[i] - base - shift + ALPHABET_SIZE) % ALPHABET_SIZE + base;
        decrypted[i] = decrypted_char;
    }
    decrypted[strlen(text)] = '\0'; // Null-terminate the decrypted string
}

// Function to display the menu
void display_menu() {
    printf("=== Simple Caesar Cipher ===\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Main function
int main() {
    char input[256];
    char prepared_text[256];
    char encrypted_text[256];
    char decrypted_text[256];
    int shift;
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter message to encrypt: ");
                scanf(" %[^\n]", input); // Read input including spaces
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);

                // Prepare the input text
                prepare_text(input, prepared_text);
                caesar_cipher(prepared_text, shift, encrypted_text);
                printf("Encrypted message: %s\n", encrypted_text);
                break;
                
            case 2:
                printf("Enter message to decrypt: ");
                scanf(" %[^\n]", input); // Read input including spaces
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);

                // Prepare the input text
                prepare_text(input, prepared_text);
                caesar_decipher(prepared_text, shift, decrypted_text);
                printf("Decrypted message: %s\n", decrypted_text);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}