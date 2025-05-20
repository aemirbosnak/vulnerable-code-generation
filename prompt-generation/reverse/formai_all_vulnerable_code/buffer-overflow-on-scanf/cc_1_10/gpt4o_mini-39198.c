//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: energetic
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            message[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            message[i] = (ch + shift - 'a') % 26 + 'a';
        }
        // Non-alphabetical characters remain unchanged
    }
}

void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            message[i] = (ch - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            message[i] = (ch - shift - 'a' + 26) % 26 + 'a';
        }
        // Non-alphabetical characters remain unchanged
    }
}

int main() {
    char message[256];
    int shift;
    int choice;

    printf("Welcome to the Caesar Cipher program!\n");
    do {
        printf("\nChoose an option:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your message to encrypt: ");
                while (getchar() != '\n'); // Clear input buffer
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character

                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                shift = shift % 26; // Normalize shift
                encrypt(message, shift);
                
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter your message to decrypt: ");
                while (getchar() != '\n'); // Clear input buffer
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character

                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                shift = shift % 26; // Normalize shift
                decrypt(message, shift);

                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting the program. Stay safe!\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}