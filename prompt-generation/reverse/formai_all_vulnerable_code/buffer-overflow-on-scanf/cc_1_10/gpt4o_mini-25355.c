//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + shift) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + shift) % 26 + 'A';
        }
        message[i] = c;
    }
}

void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' - shift + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' - shift + 26) % 26 + 'A';
        }
        message[i] = c;
    }
}

void displayMenu() {
    printf("\n--- Caesar Cipher ---\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

int main() {
    char message[256];
    int choice, shift;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                printf("Enter the shift value: ");
                scanf("%d", &shift);
                encrypt(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                printf("Enter the shift value: ");
                scanf("%d", &shift);
                decrypt(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}