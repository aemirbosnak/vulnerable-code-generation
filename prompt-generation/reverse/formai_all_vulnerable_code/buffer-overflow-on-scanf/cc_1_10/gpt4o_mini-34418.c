//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1024
#define SHIFT 3

void encrypt(char *message, char *encrypted) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        // Encrypt only alphabet characters
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = ((message[i] - 'a' + SHIFT) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = ((message[i] - 'A' + SHIFT) % 26) + 'A';
        } else {
            encrypted[i] = message[i]; // Non-alphabetic characters remain the same
        }
    }
    encrypted[i] = '\0'; // Null terminate the encrypted string
}

void decrypt(char *encrypted, char *decrypted) {
    int i;
    for (i = 0; encrypted[i] != '\0'; i++) {
        // Decrypt only alphabet characters
        if (encrypted[i] >= 'a' && encrypted[i] <= 'z') {
            decrypted[i] = ((encrypted[i] - 'a' - SHIFT + 26) % 26) + 'a'; // +26 to make sure we cycle correctly
        } else if (encrypted[i] >= 'A' && encrypted[i] <= 'Z') {
            decrypted[i] = ((encrypted[i] - 'A' - SHIFT + 26) % 26) + 'A';
        } else {
            decrypted[i] = encrypted[i]; // Non-alphabetic characters remain the same
        }
    }
    decrypted[i] = '\0'; // Null terminate the decrypted string
}

void displayMenu() {
    printf("-------------------------------------------------\n");
    printf("               SIMPLE C ENCRYPTION               \n");
    printf("-------------------------------------------------\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char encrypted[MAX_MESSAGE_LENGTH];
    char decrypted[MAX_MESSAGE_LENGTH];
    int option;

    do {
        displayMenu();
        scanf("%d", &option);
        getchar(); // Clear newline character from input buffer

        switch (option) {
            case 1:
                printf("\nEnter the message to encrypt: ");
                fgets(message, MAX_MESSAGE_LENGTH, stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character from string
                encrypt(message, encrypted);
                printf("Encrypted Message: %s\n", encrypted);
                break;

            case 2:
                printf("\nEnter the message to decrypt: ");
                fgets(encrypted, MAX_MESSAGE_LENGTH, stdin);
                encrypted[strcspn(encrypted, "\n")] = 0; // Remove newline character from string
                decrypt(encrypted, decrypted);
                printf("Decrypted Message: %s\n", decrypted);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
        printf("\n");
    } while (option != 3);

    return 0;
}