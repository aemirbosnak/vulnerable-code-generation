//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message using a key
void encrypt(char *message, int key, char *encrypted) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        // Apply modular arithmetic for encryption
        encrypted[i] = (message[i] + key) % 256; // Wrap around at 256 ASCII
    }
    encrypted[length] = '\0'; // Null-terminate the string
}

// Function to decrypt a message using a key
void decrypt(char *encrypted, int key, char *decrypted) {
    int length = strlen(encrypted);
    for (int i = 0; i < length; i++) {
        // Reverse modular arithmetic for decryption
        decrypted[i] = (encrypted[i] - key + 256) % 256; // Ensure positive values
    }
    decrypted[length] = '\0'; // Null-terminate the string
}

// Function to display the menu and handle user choice
void menu() {
    char message[256];
    char encrypted[256];
    char decrypted[256];
    int key, choice;

    printf("Welcome to the Simple Encryption Program\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove trailing newline

                printf("Enter the encryption key (integer): ");
                scanf("%d", &key);

                encrypt(message, key, encrypted);
                printf("Encrypted Message: ");
                
                for (int i = 0; i < strlen(message); i++) {
                    printf("%02X ", encrypted[i]); // Print hex representation
                }
                printf("\n");
                break;

            case 2:
                printf("Enter the encrypted message in hex (space-separated): ");
                char hexInput[512];
                fgets(hexInput, sizeof(hexInput), stdin);

                printf("Enter the decryption key (integer): ");
                scanf("%d", &key);

                // Convert hex input to binary
                char *token = strtok(hexInput, " ");
                int i = 0;
                while (token != NULL) {
                    encrypted[i++] = (char)strtol(token, NULL, 16);
                    token = strtok(NULL, " ");
                }
                encrypted[i] = '\0'; // null-terminate

                decrypt(encrypted, key, decrypted);
                printf("Decrypted Message: %s\n", decrypted);
                break;

            case 3:
                printf("Exiting the program.\n");
                return;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    }
}

// Main function to execute the program
int main() {
    menu();
    return 0;
}