//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        // Encrypt uppercase characters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase characters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt the message
void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        // Decrypt uppercase characters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase characters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

// Function to display the menu options
void displayMenu() {
    printf("🌟 Welcome to the Cheerful Encryptor! 🌟\n");
    printf("Please select an option:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

// Main function
int main() {
    char message[256];
    int choice, shift;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        // Handle the user's choice
        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                getchar(); // To consume leftover newline character from scanf
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                encrypt(message, shift);
                printf("✨ Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                getchar(); // To consume leftover newline character from scanf
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                decrypt(message, shift);
                printf("🎉 Decrypted message: %s\n", message);
                break;

            case 3:
                printf("🎈 Thank you for using Cheerful Encryptor! Come back soon! 🎈\n");
                return 0;

            default:
                printf("❌ Invalid choice! Please try again. ❌\n");
        }
        printf("\n");
    }

    return 0;
}