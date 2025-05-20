//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to perform a simple Caesar cipher encryption
void caesar_encrypt(char *input, int shift, char *output) {
    while (*input) {
        if (*input >= 'a' && *input <= 'z') {
            *output = ((*input - 'a' + shift) % 26) + 'a';
        } else if (*input >= 'A' && *input <= 'Z') {
            *output = ((*input - 'A' + shift) % 26) + 'A';
        } else {
            *output = *input; // Non-alphabetic characters remain unchanged
        }
        input++;
        output++;
    }
    *output = '\0'; // Null terminate the output string
}

// Function to perform a Caesar cipher decryption
void caesar_decrypt(char *input, int shift, char *output) {
    caesar_encrypt(input, 26 - shift, output); // Decrypting by shifting in the opposite direction
}

// Function to display menu options
void display_menu() {
    printf("Caesar Cipher Program\n");
    printf("----------------------\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    int choice, shift;
    char input[256], output[256];

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove newline character

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Shift value must be between 1 and 25.\n");
                    break;
                }

                caesar_encrypt(input, shift, output);
                printf("Encrypted Message: %s\n", output);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Shift value must be between 1 and 25.\n");
                    break;
                }

                caesar_decrypt(input, shift, output);
                printf("Decrypted Message: %s\n", output);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}