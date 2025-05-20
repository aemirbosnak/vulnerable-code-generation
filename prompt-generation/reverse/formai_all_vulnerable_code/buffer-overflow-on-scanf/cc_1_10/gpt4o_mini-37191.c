//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the plaintext using a simple Caesar cipher
void encrypt(char *plaintext, int shift, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = (ch - 'a' + shift) % 26 + 'a';
        }
        // Non-alphabetical characters are not changed
        else {
            ciphertext[i] = ch;
        }
    }
    // Null-terminate the encrypted string
    ciphertext[strlen(plaintext)] = '\0';
}

// Function to decrypt the ciphertext using a simple Caesar cipher
void decrypt(char *ciphertext, int shift, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            plaintext[i] = (ch - 'A' - shift + 26) % 26 + 'A'; // +26 to handle negative
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            plaintext[i] = (ch - 'a' - shift + 26) % 26 + 'a'; // +26 to handle negative
        }
        // Non-alphabetical characters are not changed
        else {
            plaintext[i] = ch;
        }
    }
    // Null-terminate the decrypted string
    plaintext[strlen(ciphertext)] = '\0';
}

// Function to display a menu for the user
void display_menu() {
    printf("=== Simple Encryption Program ===\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("==================================\n");
}

// Main function
int main() {
    int choice;
    char plaintext[256];
    char ciphertext[256];
    char decryptedtext[256];
    int shift;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the plaintext: ");
                getchar(); // To consume the newline character
                fgets(plaintext, sizeof(plaintext), stdin);
                plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline character

                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please enter a value between 1 and 25.\n");
                    continue;
                }

                encrypt(plaintext, shift, ciphertext);
                printf("Encrypted message: %s\n", ciphertext);
                break;

            case 2:
                printf("Enter the ciphertext: ");
                getchar(); // To consume the newline character
                fgets(ciphertext, sizeof(ciphertext), stdin);
                ciphertext[strcspn(ciphertext, "\n")] = 0; // Remove newline character

                printf("Enter shift value used for encryption (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please enter a value between 1 and 25.\n");
                    continue;
                }

                decrypt(ciphertext, shift, decryptedtext);
                printf("Decrypted message: %s\n", decryptedtext);
                break;

            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}