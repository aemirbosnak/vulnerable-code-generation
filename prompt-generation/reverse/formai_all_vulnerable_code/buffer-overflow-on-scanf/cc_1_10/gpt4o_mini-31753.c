//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 256
#define SHIFT 4

void encrypt(char *message, char *encrypted_message) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        // Check if the character is an alphabet
        if ((message[i] >= 'A' && message[i] <= 'Z')) {
            encrypted_message[i] = ((message[i] - 'A' + SHIFT) % 26) + 'A'; // Encrypt uppercase letters
        } else if ((message[i] >= 'a' && message[i] <= 'z')) {
            encrypted_message[i] = ((message[i] - 'a' + SHIFT) % 26) + 'a'; // Encrypt lowercase letters
        } else {
            encrypted_message[i] = message[i]; // Non-alphabetic characters remain unchanged
        }
    }
    encrypted_message[i] = '\0'; // Null-terminate the encrypted string
}

void decrypt(char *encrypted_message, char *decrypted_message) {
    int i;
    for (i = 0; i < strlen(encrypted_message); i++) {
        // Check if the character is an alphabet
        if ((encrypted_message[i] >= 'A' && encrypted_message[i] <= 'Z')) {
            decrypted_message[i] = ((encrypted_message[i] - 'A' - SHIFT + 26) % 26) + 'A'; // Decrypt uppercase letters
        } else if ((encrypted_message[i] >= 'a' && encrypted_message[i] <= 'z')) {
            decrypted_message[i] = ((encrypted_message[i] - 'a' - SHIFT + 26) % 26) + 'a'; // Decrypt lowercase letters
        } else {
            decrypted_message[i] = encrypted_message[i]; // Non-alphabetic characters remain unchanged
        }
    }
    decrypted_message[i] = '\0'; // Null-terminate the decrypted string
}

void display_menu() {
    printf("\n--- C Encryption Program ---\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("----------------------------\n");
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int choice;

    while (1) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1: // Encrypt
                printf("Enter a message to encrypt: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                encrypt(message, encrypted_message);
                printf("Encrypted message: %s\n", encrypted_message);
                break;

            case 2: // Decrypt
                printf("Enter a message to decrypt: ");
                fgets(encrypted_message, sizeof(encrypted_message), stdin);
                encrypted_message[strcspn(encrypted_message, "\n")] = 0; // Remove newline character
                decrypt(encrypted_message, decrypted_message);
                printf("Decrypted message: %s\n", decrypted_message);
                break;

            case 3: // Exit
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}