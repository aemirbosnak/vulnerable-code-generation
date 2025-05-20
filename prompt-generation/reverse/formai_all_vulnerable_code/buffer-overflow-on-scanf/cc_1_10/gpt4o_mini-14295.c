//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

void encrypt(char *plaintext, char *ciphertext, int key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        // Encrypt uppercase letters
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        } else {
            // Non-alphabetic characters remain unchanged
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; // Null terminate the ciphertext
}

void decrypt(char *ciphertext, char *plaintext, int key) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        // Decrypt uppercase letters
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = (ciphertext[i] - 'A' - key + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = (ciphertext[i] - 'a' - key + 26) % 26 + 'a';
        } else {
            // Non-alphabetic characters remain unchanged
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0'; // Null terminate the plaintext
}

void displayMenu() {
    printf("\n=== Simple Encryption Program ===\n");
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    char plaintext[MAX_SIZE], ciphertext[MAX_SIZE];
    int key, choice;

    // Main loop for the menu
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1: // Encrypt
                printf("Enter the text to encrypt: ");
                fgets(plaintext, MAX_SIZE, stdin);
                plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline character

                printf("Enter the encryption key (1-25): ");
                scanf("%d", &key);

                if (key < 1 || key > 25) {
                    printf("Invalid key! Please enter a key between 1 and 25.\n");
                    continue;
                }

                encrypt(plaintext, ciphertext, key);
                printf("Encrypted text: %s\n", ciphertext);
                break;

            case 2: // Decrypt
                printf("Enter the text to decrypt: ");
                fgets(ciphertext, MAX_SIZE, stdin);
                ciphertext[strcspn(ciphertext, "\n")] = 0; // Remove newline character

                printf("Enter the decryption key (1-25): ");
                scanf("%d", &key);

                if (key < 1 || key > 25) {
                    printf("Invalid key! Please enter a key between 1 and 25.\n");
                    continue;
                }

                decrypt(ciphertext, plaintext, key);
                printf("Decrypted text: %s\n", plaintext);
                break;

            case 3: // Exit
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}