//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: standalone
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

int main() {
    char message[256];
    int choice, shift;

    printf("====================================\n");
    printf(" Caesar Cipher Encryption Program\n");
    printf("====================================\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Please select an option (1-3): ");
    scanf("%d", &choice);
    getchar(); // Clear the newline character from the buffer

    while (choice != 3) {
        if (choice < 1 || choice > 2) {
            printf("Invalid option! Please select again.\n");
        } else {
            printf("Enter the message: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = 0; // Remove trailing newline

            printf("Enter the shift value (1-25): ");
            scanf("%d", &shift);
            getchar(); // Clear the newline character from the buffer

            if (shift < 1 || shift > 25) {
                printf("Invalid shift value! Please enter a value between 1 and 25.\n");
            } else {
                if (choice == 1) {
                    encrypt(message, shift);
                    printf("Encrypted message: %s\n", message);
                } else if (choice == 2) {
                    decrypt(message, shift);
                    printf("Decrypted message: %s\n", message);
                }
            }
        }

        printf("\n1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Please select an option (1-3): ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the buffer
    }

    printf("Thank you for using the Caesar Cipher program! Goodbye.\n");
    return 0;
}