//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message using Caesar cipher
void encrypt(const char *message, int shift, char *encrypted) {
    int i = 0;
    while (message[i] != '\0') {
        // Encrypt uppercase letters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = (message[i] - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = (message[i] - 'a' + shift) % 26 + 'a';
        }
        // Leave non-alphabetical characters unchanged
        else {
            encrypted[i] = message[i];
        }
        i++;
    }
    encrypted[i] = '\0';  // Null-terminate the string
}

// Function to decrypt a message using Caesar cipher
void decrypt(const char *encrypted, int shift, char *decrypted) {
    int i = 0;
    while (encrypted[i] != '\0') {
        // Decrypt uppercase letters
        if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = (encrypted[i] - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = (encrypted[i] - 'a' - shift + 26) % 26 + 'a';
        }
        // Leave non-alphabetical characters unchanged
        else {
            decrypted[i] = encrypted[i];
        }
        i++;
    }
    decrypted[i] = '\0';  // Null-terminate the string
}

int main() {
    int shift;
    char message[256];
    char encrypted[256];
    char decrypted[256];
    int choice;

    printf("Welcome to the Simple Caesar Cipher Cryptography Program!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character left in the buffer

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(message, sizeof(message), stdin);
                // Remove newline character if exists
                message[strcspn(message, "\n")] = '\0';

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);

                // Normalize the shift value to be within range
                shift = shift % 26;
                encrypt(message, shift, encrypted);

                printf("Encrypted message: %s\n", encrypted);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(encrypted, sizeof(encrypted), stdin);
                encrypted[strcspn(encrypted, "\n")] = '\0';

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);

                // Normalize the shift value to be within range
                shift = shift % 26;
                decrypt(encrypted, shift, decrypted);

                printf("Decrypted message: %s\n", decrypted);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}