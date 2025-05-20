//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024
#define SHIFT 5 // Simple Caesar cipher shift

void encrypt(char *plaintext, char *ciphertext) {
    int i = 0;
    while (plaintext[i] != '\0') {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = ((plaintext[i] - 'a' + SHIFT) % 26) + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = ((plaintext[i] - 'A' + SHIFT) % 26) + 'A';
        } else {
            ciphertext[i] = plaintext[i]; // Non-alphabetic characters remain the same
        }
        i++;
    }
    ciphertext[i] = '\0'; // Null-terminate the ciphertext string
}

void decrypt(char *ciphertext, char *plaintext) {
    int i = 0;
    while (ciphertext[i] != '\0') {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = ((ciphertext[i] - 'a' - SHIFT + 26) % 26) + 'a';
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = ((ciphertext[i] - 'A' - SHIFT + 26) % 26) + 'A';
        } else {
            plaintext[i] = ciphertext[i]; // Non-alphabetic characters remain the same
        }
        i++;
    }
    plaintext[i] = '\0'; // Null-terminate the plaintext string
}

void displayMenu() {
    printf("Simple Encryption System\n");
    printf("=========================\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Please select an option: ");
}

int main() {
    char plaintext[MAX_SIZE];
    char ciphertext[MAX_SIZE];
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // consume leftover newline

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(plaintext, MAX_SIZE, stdin);
                // Remove newline character
                plaintext[strcspn(plaintext, "\n")] = 0;
                encrypt(plaintext, ciphertext);
                printf("Encrypted message: %s\n\n", ciphertext);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(ciphertext, MAX_SIZE, stdin);
                // Remove newline character
                ciphertext[strcspn(ciphertext, "\n")] = 0;
                decrypt(ciphertext, plaintext);
                printf("Decrypted message: %s\n\n", plaintext);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please select a valid option.\n\n");
                break;
        }
    }

    return 0;
}