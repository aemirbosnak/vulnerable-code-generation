//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256
#define SHIFT_KEY 5

// Function to encrypt the message
void encrypt(char *message, char *encrypted) {
    int i;
    for (i = 0; message[i] != '\0' && i < MAX_LEN; i++) {
        // Encrypt using modular arithmetic
        encrypted[i] = (message[i] + SHIFT_KEY) % 256; 
    }
    encrypted[i] = '\0'; // Null-terminate the string
}

// Function to decrypt the message
void decrypt(char *encrypted, char *decrypted) {
    int i;
    for (i = 0; encrypted[i] != '\0' && i < MAX_LEN; i++) {
        // Decrypt using modular arithmetic
        decrypted[i] = (encrypted[i] - SHIFT_KEY + 256) % 256; 
    }
    decrypted[i] = '\0'; // Null-terminate the string
}

// Function to display menus and get user input
void menu() {
    char message[MAX_LEN];
    char encrypted[MAX_LEN];
    char decrypted[MAX_LEN];
    int choice;

    while (1) {
        printf("\n--- Simple Encryption Program ---\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter a message to encrypt: ");
                fgets(message, MAX_LEN, stdin);
                message[strcspn(message, "\n")] = '\0'; // Remove newline character

                encrypt(message, encrypted);
                printf("Encrypted message: ");
                for (int i = 0; encrypted[i] != '\0'; i++) {
                    printf("%c", encrypted[i]);
                }
                printf("\n");
                break;
            case 2:
                printf("Enter a message to decrypt: ");
                fgets(encrypted, MAX_LEN, stdin);
                encrypted[strcspn(encrypted, "\n")] = '\0'; // Remove newline character

                decrypt(encrypted, decrypted);
                printf("Decrypted message: %s\n", decrypted);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}