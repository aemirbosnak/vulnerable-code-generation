//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void encrypt(const char *plaintext, char *ciphertext, int key) {
    int i;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        // Simple Caesar Cipher encryption
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        } else {
            ciphertext[i] = plaintext[i]; // Non-alphabetic characters remain unchanged
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the ciphertext string
}

void decrypt(const char *ciphertext, char *plaintext, int key) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; ++i) {
        // Simple Caesar Cipher decryption
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = (ciphertext[i] - 'a' - key + 26) % 26 + 'a';
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = (ciphertext[i] - 'A' - key + 26) % 26 + 'A';
        } else {
            plaintext[i] = ciphertext[i]; // Non-alphabetic characters remain unchanged
        }
    }
    plaintext[i] = '\0'; // Null-terminate the plaintext string
}

void display_menu() {
    printf("== Caesar Cipher Encryption Program ==\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("=======================================\n");
    printf("Choose an option: ");
}

int main() {
    char plaintext[MAX_LEN];
    char ciphertext[MAX_LEN];
    char decryptedtext[MAX_LEN];
    int key;
    int choice;

    // Loop until the user decides to exit
    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Consume newline character after the number input

        switch (choice) {
            case 1: // Encrypting a message
                printf("Enter the plaintext: ");
                fgets(plaintext, MAX_LEN, stdin);
                plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove trailing newline

                printf("Enter the encryption key (0-25): ");
                scanf("%d", &key);
                
                // Ensure the key is within the range
                if (key < 0 || key > 25) {
                    printf("Invalid key. Please enter a key between 0 and 25.\n");
                    break;
                }

                encrypt(plaintext, ciphertext, key);
                printf("Encrypted message: %s\n", ciphertext);
                break;

            case 2: // Decrypting a message
                printf("Enter the ciphertext: ");
                fgets(ciphertext, MAX_LEN, stdin);
                ciphertext[strcspn(ciphertext, "\n")] = '\0'; // Remove trailing newline

                printf("Enter the decryption key (0-25): ");
                scanf("%d", &key);
                
                // Ensure the key is within the range
                if (key < 0 || key > 25) {
                    printf("Invalid key. Please enter a key between 0 and 25.\n");
                    break;
                }

                decrypt(ciphertext, decryptedtext, key);
                printf("Decrypted message: %s\n", decryptedtext);
                break;

            case 3: // Exit
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
                break;
        }
    }

    return 0; // Exit the program successfully
}