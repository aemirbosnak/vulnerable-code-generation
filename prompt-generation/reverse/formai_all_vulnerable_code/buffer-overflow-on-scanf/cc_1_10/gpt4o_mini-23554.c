//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char c = message[i];
        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            message[i] = 'A' + (c - 'A' + shift) % 26;
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            message[i] = 'a' + (c - 'a' + shift) % 26;
        }
    }
}

void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char c = message[i];
        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            message[i] = 'A' + (c - 'A' - shift + 26) % 26;
        }
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            message[i] = 'a' + (c - 'a' - shift + 26) % 26;
        }
    }
}

void displayMenu() {
    printf("\n=== Caesar Cipher Encryption Program ===\n");
    printf("1. Encrypt a Message\n");
    printf("2. Decrypt a Message\n");
    printf("3. Exit\n");
    printf("=========================================\n");
    printf("Please select an option: ");
}

int main() {
    char message[256];
    int choice, shift;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter your message: ");
        // Clear the buffer before taking string input
        getchar();
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0; // Remove trailing newline

        printf("Enter the shift amount (1-25): ");
        scanf("%d", &shift);

        // Ensure shift amount is valid
        if (shift < 1 || shift > 25) {
            printf("Invalid shift amount. Please enter a number between 1 and 25.\n");
            continue;
        }

        switch (choice) {
            case 1:
                encrypt(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                decrypt(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}